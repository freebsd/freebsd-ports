--- src/3rdparty/chromium/services/catalog/store.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/services/catalog/store.cc
@@ -36,5 +36,7 @@ const char Store::kRequiredFilesKey_PlatformValue_MacO
 const char Store::kRequiredFilesKey_PlatformValue_Android[] = "android";
 // static
 const char Store::kRequiredFilesKey_PlatformValue_Fuchsia[] = "fuchsia";
+// static
+const char Store::kRequiredFilesKey_PlatformValue_FreeBSD[] = "freebsd";
 
 }  // namespace catalog
