--- third_party/pdfium/third_party/base/logging.h.orig	2015-04-19 17:22:14.000000000 +0200
+++ third_party/pdfium/third_party/base/logging.h	2015-04-19 17:22:28.000000000 +0200
@@ -10,7 +10,7 @@
 #define CHECK(condition)                                                \
   if (!(condition)) {                                                   \
     abort();                                                            \
-    *(reinterpret_cast<volatile char*>(NULL) + 42) = 0x42;              \
+    *(reinterpret_cast<volatile char*>(__null) + 42) = 0x42;              \
   }
 
 #define NOTREACHED() abort()
