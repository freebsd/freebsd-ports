--- third_party/pdfium/third_party/logging.h.orig	2014-10-10 09:15:55 UTC
+++ third_party/pdfium/third_party/logging.h
@@ -10,7 +10,7 @@
 #define CHECK(condition)                                                \
   if (!(condition)) {                                                   \
     abort();                                                            \
-    *(reinterpret_cast<volatile char*>(NULL) + 42) = 0x42;              \
+    *(reinterpret_cast<volatile char*>(__null) + 42) = 0x42;              \
   }
 
 #define NOTREACHED() abort()
