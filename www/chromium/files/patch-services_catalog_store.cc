--- services/catalog/store.cc.orig	2019-03-11 22:01:01 UTC
+++ services/catalog/store.cc
@@ -38,5 +38,7 @@ const char Store::kRequiredFilesKey_PlatformValue_MacO
 const char Store::kRequiredFilesKey_PlatformValue_Android[] = "android";
 // static
 const char Store::kRequiredFilesKey_PlatformValue_Fuchsia[] = "fuchsia";
+// static
+const char Store::kRequiredFilesKey_PlatformValue_FreeBSD[] = "freebsd";
 
 }  // namespace catalog
