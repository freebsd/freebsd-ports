--- Source/WebKit2/Shared/Plugins/unix/PluginSearchPath.cpp.orig	2016-01-28 08:55:09 UTC
+++ Source/WebKit2/Shared/Plugins/unix/PluginSearchPath.cpp
@@ -50,6 +50,7 @@ Vector<String> pluginsDirectories()
 
     result.append(homeDirectoryPath() + "/.mozilla/plugins");
     result.append(homeDirectoryPath() + "/.netscape/plugins");
+    result.append("%%BROWSER_PLUGINS_DIR%%");
     result.append("/usr/lib/browser/plugins");
     result.append("/usr/local/lib/mozilla/plugins");
     result.append("/usr/lib/firefox/plugins");
