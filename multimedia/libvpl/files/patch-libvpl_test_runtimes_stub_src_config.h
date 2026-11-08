--- libvpl/test/runtimes/stub/src/config.h.orig	2025-12-17 23:04:39 UTC
+++ libvpl/test/runtimes/stub/src/config.h
@@ -13,7 +13,7 @@
 
 #include "vpl/mfx.h"
 
-#if defined(__linux__)
+#if defined(__unix__)
     #define vsprintf_s(s, l, m, a) vsprintf(s, m, a)
 #endif
 
