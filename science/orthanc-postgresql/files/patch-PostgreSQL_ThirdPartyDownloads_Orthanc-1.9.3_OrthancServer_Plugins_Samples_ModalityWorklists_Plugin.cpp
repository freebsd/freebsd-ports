--- PostgreSQL/ThirdPartyDownloads/Orthanc-1.9.3/OrthancServer/Plugins/Samples/ModalityWorklists/Plugin.cpp.orig	2021-05-07 07:22:38 UTC
+++ PostgreSQL/ThirdPartyDownloads/Orthanc-1.9.3/OrthancServer/Plugins/Samples/ModalityWorklists/Plugin.cpp
@@ -162,7 +162,7 @@ OrthancPluginErrorCode Callback(OrthancPluginWorklistA
         if (type == fs::regular_file ||
             type == fs::reparse_file)   // cf. BitBucket issue #11
         {
-          std::string extension = fs::extension(it->path());
+          std::string extension = it->path().extension().string();
           std::transform(extension.begin(), extension.end(), extension.begin(), tolower);  // Convert to lowercase
 
           if (extension == ".wl")
