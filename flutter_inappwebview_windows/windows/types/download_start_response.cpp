#include "../utils/flutter.h"
#include "download_start_response.h"

namespace flutter_inappwebview_plugin
{
  DownloadStartResponse::DownloadStartResponse(const bool& handled,
    const std::optional<DownloadStartResponseAction>& action)
    : handled(handled), action(action)
  {}

  DownloadStartResponse::DownloadStartResponse(const flutter::EncodableMap& map)
    : DownloadStartResponse(get_fl_map_value<bool>(map, "handled"),
      DownloadStartResponseActionFromInteger(get_optional_fl_map_value<int64_t>(map, "action")))
  {}

  flutter::EncodableMap DownloadStartResponse::toEncodableMap() const
  {
    return flutter::EncodableMap{
    {"handled", make_fl_value(handled)},
    {"action", make_fl_value(DownloadStartResponseActionToInteger(action))}
    };
  }
}