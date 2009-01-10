--- WebCore/plugins/PluginDatabase.cpp.orig	2008-05-26 01:03:07.236973838 -0700
+++ WebCore/plugins/PluginDatabase.cpp	2008-05-26 01:03:52.356436787 -0700
@@ -281,6 +281,7 @@
     userPluginPath.append(String("/.netscape/plugins"));
     paths.append(userPluginPath);
 
+    paths.append("%%BROWSER_PLUGINS%%");
     paths.append("/usr/lib/browser/plugins");
     paths.append("/usr/local/lib/mozilla/plugins");
     paths.append("/usr/lib/firefox/plugins");
