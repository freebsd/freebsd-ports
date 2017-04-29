--- services/catalog/store.h.orig	2017-04-19 19:06:37 UTC
+++ services/catalog/store.h
@@ -33,6 +33,7 @@ class Store {
   static const char kRequiredFilesKey_PlatformValue_Linux[];
   static const char kRequiredFilesKey_PlatformValue_MacOSX[];
   static const char kRequiredFilesKey_PlatformValue_Android[];
+  static const char kRequiredFilesKey_PlatformValue_FreeBSD[];
 };
 
 }  // namespace catalog
