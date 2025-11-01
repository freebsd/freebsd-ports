--- libtransmission/torrent.cc.orig	2025-10-15 08:51:36 UTC
+++ libtransmission/torrent.cc
@@ -6,6 +6,7 @@
 #include <algorithm>
 #include <array>
 #include <cerrno> // EINVAL
+#include <chrono>
 #include <climits> /* INT_MAX */
 #include <csignal> /* signal() */
 #include <ctime>
@@ -438,6 +439,8 @@ void torrentCallScript(tr_torrent const* tor, std::str
         return;
     }
 
+    auto const now = tr_time();
+
     auto torrent_dir = tr_pathbuf{ tor->currentDir() };
     tr_sys_path_native_separators(std::data(torrent_dir));
 
@@ -447,7 +450,7 @@ void torrentCallScript(tr_torrent const* tor, std::str
     auto const labels_str = buildLabelsString(tor);
     auto const trackers_str = buildTrackersString(tor);
     auto const bytes_downloaded_str = std::to_string(tor->downloadedCur + tor->downloadedPrev);
-    auto const localtime_str = fmt::format("{:%a %b %d %T %Y%n}", fmt::localtime(tr_time()));
+    auto const localtime_str = fmt::format("{:%a %b %d %T %Y%n}", *std::localtime(&now));
 
     auto const env = std::map<std::string_view, std::string_view>{
         { "TR_APP_VERSION"sv, SHORT_VERSION_STRING },
