--- MySQL/ThirdPartyDownloads/Orthanc-1.9.3/OrthancFramework/Sources/SystemToolbox.cpp.orig	2021-05-07 07:22:38 UTC
+++ MySQL/ThirdPartyDownloads/Orthanc-1.9.3/OrthancFramework/Sources/SystemToolbox.cpp
@@ -727,7 +727,7 @@ namespace Orthanc
 
   MimeType SystemToolbox::AutodetectMimeType(const std::string& path)
   {
-    std::string extension = boost::filesystem::extension(path);
+    std::string extension = boost::filesystem::path(path).extension().string();
     Toolbox::ToLowerCase(extension);
 
     // http://en.wikipedia.org/wiki/Mime_types
