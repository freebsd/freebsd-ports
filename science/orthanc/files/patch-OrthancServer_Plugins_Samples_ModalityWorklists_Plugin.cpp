--- OrthancServer/Plugins/Samples/ModalityWorklists/Plugin.cpp.orig	2024-01-31 11:33:17 UTC
+++ OrthancServer/Plugins/Samples/ModalityWorklists/Plugin.cpp
@@ -164,7 +164,7 @@ OrthancPluginErrorCode Callback(OrthancPluginWorklistA
         if (type == fs::regular_file ||
             type == fs::reparse_file)   // cf. BitBucket issue #11
         {
-          std::string extension = fs::extension(it->path());
+          std::string extension = it->path().extension().string();
           std::transform(extension.begin(), extension.end(), extension.begin(), tolower);  // Convert to lowercase
 
           if (extension == ".wl")
