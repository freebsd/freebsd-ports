--- services/catalog/store.cc.orig	2017-09-05 21:05:23.000000000 +0200
+++ services/catalog/store.cc	2017-09-06 21:21:50.819060000 +0200
@@ -34,5 +34,7 @@
 const char Store::kRequiredFilesKey_PlatformValue_Android[] = "android";
 // static
 const char Store::kRequiredFilesKey_PlatformValue_Fuchsia[] = "fuchsia";
+// static
+const char Store::kRequiredFilesKey_PlatformValue_FreeBSD[] = "freebsd";
 
 }  // namespace catalog
