--- autobahn/nvx/_utf8validator.c.orig	2023-10-11 07:35:12 UTC
+++ autobahn/nvx/_utf8validator.c
@@ -28,7 +28,9 @@
 #include <stdint.h>
 
 // http://stackoverflow.com/questions/11228855/header-files-for-simd-intrinsics
+#if defined(__amd64__) || defined(__i386__)
 #include <x86intrin.h>
+#endif
 
 
 #define UTF8_ACCEPT 0
