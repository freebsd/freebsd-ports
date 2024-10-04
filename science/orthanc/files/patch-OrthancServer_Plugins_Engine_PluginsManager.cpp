--- OrthancServer/Plugins/Engine/PluginsManager.cpp.orig	2024-01-31 11:33:17 UTC
+++ OrthancServer/Plugins/Engine/PluginsManager.cpp
@@ -295,7 +295,7 @@ namespace Orthanc
       }
       else
       {
-        std::string extension = boost::filesystem::extension(it->path());
+        std::string extension = it->path().extension().string();
         Toolbox::ToLowerCase(extension);
 
         if (extension == PLUGIN_EXTENSION)
