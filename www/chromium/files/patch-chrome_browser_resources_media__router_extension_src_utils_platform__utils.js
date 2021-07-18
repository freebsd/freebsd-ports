--- chrome/browser/resources/media_router/extension/src/utils/platform_utils.js.orig	2021-06-11 09:26:56 UTC
+++ chrome/browser/resources/media_router/extension/src/utils/platform_utils.js
@@ -58,5 +58,8 @@ mr.PlatformUtils.getCurrentOS = function() {
   if (userAgent.includes('Linux')) {
     return mr.PlatformUtils.OS.LINUX;
   }
+  if (userAgent.includes('FreeBSD')) {
+    return mr.PlatformUtils.OS.LINUX;
+  }
   return mr.PlatformUtils.OS.OTHER;
 };
