--- services/catalog/store.h.orig	2017-09-05 21:05:23.000000000 +0200
+++ services/catalog/store.h	2017-09-06 21:16:22.831744000 +0200
@@ -34,6 +34,7 @@
   static const char kRequiredFilesKey_PlatformValue_MacOSX[];
   static const char kRequiredFilesKey_PlatformValue_Android[];
   static const char kRequiredFilesKey_PlatformValue_Fuchsia[];
+  static const char kRequiredFilesKey_PlatformValue_FreeBSD[];
 };
 
 }  // namespace catalog
