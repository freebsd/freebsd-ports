--- Source/WebCore/plugins/PluginDatabase.cpp.orig	2011-01-11 16:24:29.000000000 +0000
+++ Source/WebCore/plugins/PluginDatabase.cpp	2011-01-11 16:24:54.000000000 +0000
@@ -375,6 +375,7 @@ Vector<String> PluginDatabase::defaultPl
     userPluginPath.append(String("/.netscape/plugins"));
     paths.append(userPluginPath);
 
+    paths.append("%%BROWSER_PLUGINS_DIR%%");
     paths.append("/usr/lib/browser/plugins");
     paths.append("/usr/local/lib/mozilla/plugins");
     paths.append("/usr/lib/firefox/plugins");
