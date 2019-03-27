--- src/3rdparty/chromium/services/catalog/store.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/services/catalog/store.h
@@ -36,6 +36,7 @@ class Store {
   static const char kRequiredFilesKey_PlatformValue_MacOSX[];
   static const char kRequiredFilesKey_PlatformValue_Android[];
   static const char kRequiredFilesKey_PlatformValue_Fuchsia[];
+  static const char kRequiredFilesKey_PlatformValue_FreeBSD[];
 };
 
 }  // namespace catalog
