--- remoting/webapp/base/js/platform.js.orig	2017-08-10 16:21:23.900363000 +0200
+++ remoting/webapp/base/js/platform.js	2017-08-10 16:24:46.113671000 +0200
@@ -107,6 +107,14 @@
     return result;
   }
 
+  match = new RegExp('FreeBSD ([a-zA-Z0-9_]*)').exec(userAgent);
+  if (match && (match.length >= 2)) {
+    result.osName = remoting.Os.LINUX;
+    result.osVersion = '';
+    result.cpu = match[1];
+    return result;
+  }
+
   match = new RegExp('([a-zA-Z]*) Mac OS X ([0-9_]*)').exec(userAgent);
   if (match && (match.length >= 3)) {
     result.osName = remoting.Os.MAC;
