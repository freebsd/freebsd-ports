--- src/mgui/project/add.cpp.orig	2012-02-08 13:19:21.000000000 +0100
+++ src/mgui/project/add.cpp	2012-06-05 17:53:01.000000000 +0200
@@ -420,7 +420,7 @@
 static std::string StandFNameOut(const fs::path& pth)
 {
     return "<span style=\"italic\" underline=\"low\">" + 
-                    pth.leaf() + "</span>";
+                    pth.filename().string() + "</span>";
 }
 
 #if GTK_CHECK_VERSION(2,18,0)
@@ -465,7 +465,7 @@
     {
         const std::string fname = paths[0];
         fs::path pth(fname); 
-        std::string leaf = pth.leaf();
+        std::string leaf = pth.filename().string();
         {
             static re::pattern dvd_video_vob("(VIDEO_TS|VTS_[0-9][0-9]_[0-9]).VOB", 
                                               re::pattern::perl|re::pattern::icase);
