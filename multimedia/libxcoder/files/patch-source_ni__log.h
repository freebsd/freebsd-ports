--- source/ni_log.h.orig	2026-10-17 00:01:03 UTC
+++ source/ni_log.h
@@ -44,7 +44,7 @@
   #else
     #define LIB_API_LOG
   #endif
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
   #define LIB_API_LOG
 #endif
 
