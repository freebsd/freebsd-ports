--- source/ni_bitstream.h.orig	2026-10-17 00:01:03 UTC
+++ source/ni_bitstream.h
@@ -52,7 +52,7 @@ extern "C" {
   #else
     #define LIB_API_BITSTREAM
   #endif
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
   #define LIB_API_BITSTREAM
 #endif
 
