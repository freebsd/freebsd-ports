--- OrthancServer/Sources/OrthancConfiguration.cpp.orig	2024-01-31 11:33:17 UTC
+++ OrthancServer/Sources/OrthancConfiguration.cpp
@@ -114,7 +114,7 @@ namespace Orthanc
     {
       if (!is_directory(it->status()))
       {
-        std::string extension = boost::filesystem::extension(it->path());
+        std::string extension = it->path().extension().string();
         Toolbox::ToLowerCase(extension);
 
         if (extension == ".json")
