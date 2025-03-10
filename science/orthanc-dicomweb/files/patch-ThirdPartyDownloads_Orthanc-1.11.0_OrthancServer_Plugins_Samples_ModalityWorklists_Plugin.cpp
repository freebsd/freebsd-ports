--- ThirdPartyDownloads/Orthanc-1.11.0/OrthancServer/Plugins/Samples/ModalityWorklists/Plugin.cpp.orig	2022-05-09 09:19:44 UTC
+++ ThirdPartyDownloads/Orthanc-1.11.0/OrthancServer/Plugins/Samples/ModalityWorklists/Plugin.cpp
@@ -163,7 +163,7 @@ OrthancPluginErrorCode Callback(OrthancPluginWorklistA
         if (type == fs::regular_file ||
             type == fs::reparse_file)   // cf. BitBucket issue #11
         {
-          std::string extension = fs::extension(it->path());
+          std::string extension = it->path().extension().string();
           std::transform(extension.begin(), extension.end(), extension.begin(), tolower);  // Convert to lowercase
 
           if (extension == ".wl")
