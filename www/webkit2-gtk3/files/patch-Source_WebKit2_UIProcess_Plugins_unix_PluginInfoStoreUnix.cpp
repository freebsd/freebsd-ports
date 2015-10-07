--- Source/WebKit2/UIProcess/Plugins/unix/PluginInfoStoreUnix.cpp.orig	2015-01-15 18:15:59.000000000 +0100
+++ Source/WebKit2/UIProcess/Plugins/unix/PluginInfoStoreUnix.cpp	2015-01-22 15:16:17.352196197 +0100
@@ -48,6 +48,7 @@
 
     result.append(homeDirectoryPath() + "/.mozilla/plugins");
     result.append(homeDirectoryPath() + "/.netscape/plugins");
+    result.append("%%BROWSER_PLUGINS_DIR%%");
     result.append("/usr/lib/browser/plugins");
     result.append("/usr/local/lib/mozilla/plugins");
     result.append("/usr/lib/firefox/plugins");
