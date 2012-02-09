--- third_party/leveldatabase/env_chromium.cc.orig	2012-01-18 11:12:19.000000000 +0200
+++ third_party/leveldatabase/env_chromium.cc	2012-01-29 19:48:55.000000000 +0200
@@ -33,7 +33,7 @@
 namespace {
 
 #if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_ANDROID) || \
-    defined(OS_OPENBSD)
+    defined(OS_BSD)
 // The following are glibc-specific
 
 size_t fread_unlocked(void *ptr, size_t size, size_t n, FILE *file) {
