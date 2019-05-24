--- base/test/generate_fontconfig_caches.cc.orig	2019-04-30 22:22:28 UTC
+++ base/test/generate_fontconfig_caches.cc
@@ -52,14 +52,21 @@ int main() {
 
   // Delete directory before generating fontconfig caches. This will notify
   // future fontconfig_caches changes.
-  CHECK(base::DeleteFile(fontconfig_caches, /*recursive=*/true));
 
+  CHECK(base::DeleteFile(fontconfig_caches, /*recursive=*/true));
   base::SetUpFontconfig();
   FcInit();
   FcFini();
 
   // Check existence of intended fontconfig cache file.
+#if defined(OS_BSD)
+  // Our version of fontconfig is too old to respect .uuid files in font directories,
+  // so we check for the CACHEDIR.TAG file instead
   CHECK(base::PathExists(
+      fontconfig_caches.Append("CACHEDIR.TAG")));
+#else
+  CHECK(base::PathExists(
       fontconfig_caches.Append(base::StrCat({uuid, "-le64.cache-7"}))));
+#endif
   return 0;
 }
