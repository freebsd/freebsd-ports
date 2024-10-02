--- libfuse/lib/fuse.c.orig	2024-02-29 20:41:22 UTC
+++ libfuse/lib/fuse.c
@@ -48,8 +48,10 @@
 #include <time.h>
 #include <unistd.h>
 
-#ifdef HAVE_MALLOC_TRIM
+#ifdef __linux__
 #include <malloc.h>
+#else
+#define malloc_trim(x) ((void)(x))
 #endif
 
 #define FUSE_UNKNOWN_INO UINT64_MAX
