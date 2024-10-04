--- OrthancFramework/Sources/SystemToolbox.cpp.orig	2024-01-31 11:33:17 UTC
+++ OrthancFramework/Sources/SystemToolbox.cpp
@@ -774,7 +774,7 @@ namespace Orthanc
 
   MimeType SystemToolbox::AutodetectMimeType(const std::string& path)
   {
-    std::string extension = boost::filesystem::extension(path);
+    std::string extension = boost::filesystem::path(path).extension().string();
     Toolbox::ToLowerCase(extension);
 
     // http://en.wikipedia.org/wiki/Mime_types
