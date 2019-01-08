--- base/test/generate_fontconfig_caches.cc.orig	2018-12-16 02:19:42.000000000 +0100
+++ base/test/generate_fontconfig_caches.cc	2018-12-16 02:19:45.432130000 +0100
@@ -57,7 +57,14 @@
   base::TearDownFontconfig();
 
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
