--- source/ni_getopt.h.orig	2026-10-17 00:01:03 UTC
+++ source/ni_getopt.h
@@ -42,7 +42,7 @@ extern "C"
 #else
 #define LIB_API_GETOPT
 #endif
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
 #define LIB_API_GETOPT
 #endif
 
