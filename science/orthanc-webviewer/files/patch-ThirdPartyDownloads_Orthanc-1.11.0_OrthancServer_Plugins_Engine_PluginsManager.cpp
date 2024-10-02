--- ThirdPartyDownloads/Orthanc-1.11.0/OrthancServer/Plugins/Engine/PluginsManager.cpp.orig	2022-05-09 09:19:44 UTC
+++ ThirdPartyDownloads/Orthanc-1.11.0/OrthancServer/Plugins/Engine/PluginsManager.cpp
@@ -292,7 +292,7 @@ namespace Orthanc
       }
       else
       {
-        std::string extension = boost::filesystem::extension(it->path());
+        std::string extension = it->path().extension().string();
         Toolbox::ToLowerCase(extension);
 
         if (extension == PLUGIN_EXTENSION)
