--- src/3rdparty/chromium/third_party/pdfium/third_party/base/logging.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/third_party/pdfium/third_party/base/logging.h
@@ -10,7 +10,7 @@
 
 #ifndef _WIN32
 #define NULL_DEREF_IF_POSSIBLE \
-  *(reinterpret_cast<volatile char*>(NULL) + 42) = 0x42;
+  *(reinterpret_cast<volatile char*>(__null) + 42) = 0x42;
 #else
 #define NULL_DEREF_IF_POSSIBLE
 #endif
