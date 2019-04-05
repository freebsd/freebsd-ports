--- remoting/webapp/base/js/platform.js.orig	2019-03-11 22:01:01 UTC
+++ remoting/webapp/base/js/platform.js
@@ -107,6 +107,14 @@ remoting.getSystemInfo = function() {
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
