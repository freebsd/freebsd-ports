--- avidemux_core/ADM_core/src/ADM_folder_linux.cpp.orig	2021-03-07 06:18:22 UTC
+++ avidemux_core/ADM_core/src/ADM_folder_linux.cpp
@@ -39,7 +39,7 @@ static std::string ADM_i18nDir;
 static std::string canonize(const std::string &in)
 {
     std::string out;
-    char *simple2=canonicalize_file_name(in.c_str());
+    char *simple2=realpath(in.c_str(),nullptr);
     if(simple2)
     {
         out=std::string(simple2);
