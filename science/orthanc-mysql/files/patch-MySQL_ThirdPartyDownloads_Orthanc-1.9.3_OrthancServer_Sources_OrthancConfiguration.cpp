--- MySQL/ThirdPartyDownloads/Orthanc-1.9.3/OrthancServer/Sources/OrthancConfiguration.cpp.orig	2021-05-07 07:22:38 UTC
+++ MySQL/ThirdPartyDownloads/Orthanc-1.9.3/OrthancServer/Sources/OrthancConfiguration.cpp
@@ -123,7 +123,7 @@ namespace Orthanc
     {
       if (!is_directory(it->status()))
       {
-        std::string extension = boost::filesystem::extension(it->path());
+        std::string extension = it->path().extension().string();
         Toolbox::ToLowerCase(extension);
 
         if (extension == ".json")
