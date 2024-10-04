--- MySQL/ThirdPartyDownloads/Orthanc-1.9.3/OrthancServer/Plugins/Engine/PluginsManager.cpp.orig	2021-05-07 07:22:38 UTC
+++ MySQL/ThirdPartyDownloads/Orthanc-1.9.3/OrthancServer/Plugins/Engine/PluginsManager.cpp
@@ -303,7 +303,7 @@ namespace Orthanc
       }
       else
       {
-        std::string extension = boost::filesystem::extension(it->path());
+        std::string extension = it->path().extension().string();
         Toolbox::ToLowerCase(extension);
 
         if (extension == PLUGIN_EXTENSION)
