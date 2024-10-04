--- ThirdPartyDownloads/Orthanc-1.11.0/OrthancServer/Sources/OrthancConfiguration.cpp.orig	2022-05-09 09:19:44 UTC
+++ ThirdPartyDownloads/Orthanc-1.11.0/OrthancServer/Sources/OrthancConfiguration.cpp
@@ -113,7 +113,7 @@ namespace Orthanc
     {
       if (!is_directory(it->status()))
       {
-        std::string extension = boost::filesystem::extension(it->path());
+        std::string extension = it->path().extension().string();
         Toolbox::ToLowerCase(extension);
 
         if (extension == ".json")
