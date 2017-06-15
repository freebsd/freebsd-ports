--- Source/WebCore/plugins/PluginDatabase.cpp.orig	2016-04-10 06:48:37 UTC
+++ Source/WebCore/plugins/PluginDatabase.cpp
@@ -394,6 +394,7 @@ Vector<String> PluginDatabase::defaultPl
     userPluginPath.append(String("/.netscape/plugins"));
     paths.append(userPluginPath);
 
+    paths.append("%%BROWSER_PLUGINS_DIR%%");
     paths.append("/usr/lib/browser/plugins");
     paths.append("/usr/local/lib/mozilla/plugins");
     paths.append("/usr/lib/firefox/plugins");
