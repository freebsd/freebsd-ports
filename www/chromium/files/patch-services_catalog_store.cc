--- services/catalog/store.cc.orig	2017-06-05 19:03:11 UTC
+++ services/catalog/store.cc
@@ -32,4 +32,6 @@ const char Store::kRequiredFilesKey_PlatformValue_Linu
 const char Store::kRequiredFilesKey_PlatformValue_MacOSX[] = "macosx";
 // static
 const char Store::kRequiredFilesKey_PlatformValue_Android[] = "android";
+// static
+const char Store::kRequiredFilesKey_PlatformValue_FreeBSD[] = "freebsd";
 }  // namespace catalog
