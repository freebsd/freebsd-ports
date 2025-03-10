--- ThirdPartyDownloads/Orthanc-1.11.0/OrthancFramework/Sources/SystemToolbox.cpp.orig	2022-05-09 09:19:44 UTC
+++ ThirdPartyDownloads/Orthanc-1.11.0/OrthancFramework/Sources/SystemToolbox.cpp
@@ -728,7 +728,7 @@ namespace Orthanc
 
   MimeType SystemToolbox::AutodetectMimeType(const std::string& path)
   {
-    std::string extension = boost::filesystem::extension(path);
+    std::string extension = boost::filesystem::path(path).extension().string();
     Toolbox::ToLowerCase(extension);
 
     // http://en.wikipedia.org/wiki/Mime_types
