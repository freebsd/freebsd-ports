--- third_party/pdfium/third_party/base/logging.h.orig	2016-05-25 15:02:25.000000000 -0400
+++ third_party/pdfium/third_party/base/logging.h	2016-05-27 11:35:39.166720000 -0400
@@ -10,7 +10,7 @@
 
 #ifndef _WIN32
 #define NULL_DEREF_IF_POSSIBLE \
-  *(reinterpret_cast<volatile char*>(NULL) + 42) = 0x42;
+  *(reinterpret_cast<volatile char*>(__null) + 42) = 0x42;
 #else
 #define NULL_DEREF_IF_POSSIBLE
 #endif
