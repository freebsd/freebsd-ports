--- talk/session/fileshare/fileshare.cc.orig	2012-07-05 15:29:12.000000000 -0700
+++ talk/session/fileshare/fileshare.cc	2012-07-05 15:45:43.000000000 -0700
@@ -670,8 +670,8 @@
         && !query.empty()
         && (sscanf(query.c_str(), "width=%u&height=%u",
                    &width, &height) == 2)) {
-      width = talk_base::_max<unsigned int>(1, talk_base::_min(width, kMaxPreviewSize));
-      height = talk_base::_max<unsigned int>(1, talk_base::_min(height, kMaxPreviewSize));
+      width = talk_base::_max<unsigned int>(1, talk_base::_min((size_t)width, kMaxPreviewSize));
+      height = talk_base::_max<unsigned int>(1, talk_base::_min((size_t)height, kMaxPreviewSize));
       std::string pathname;
       if (is_sender_) {
         talk_base::Pathname local_path;