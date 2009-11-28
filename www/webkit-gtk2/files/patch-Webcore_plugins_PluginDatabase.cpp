--- WebCore/plugins/PluginDatabase.cpp.orig	2008-11-02 03:12:05.000000000 +0800
+++ WebCore/plugins/PluginDatabase.cpp	2009-05-19 15:09:51.000000000 +0800
@@ -283,6 +283,7 @@ Vector<String> PluginDatabase::defaultPl
     userPluginPath.append(String("/.netscape/plugins"));
     paths.append(userPluginPath);
 
+    paths.append("%%BROWSER_PLUGINS_DIR%%");
     paths.append("/usr/lib/browser/plugins");
     paths.append("/usr/local/lib/mozilla/plugins");
     paths.append("/usr/lib/firefox/plugins");
