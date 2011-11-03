--- third_party/protobuf/src/google/protobuf/stubs/common.h.orig	2011-10-31 14:25:22.000000000 +0000
+++ third_party/protobuf/src/google/protobuf/stubs/common.h	2011-10-31 17:54:21.000000000 +0000
@@ -47,6 +47,10 @@
 #elif !defined(_MSC_VER)
 #include <stdint.h>
 #endif
+#if defined(__FreeBSD__)
+#undef major
+#undef minor
+#endif
 
 #if defined(_MSC_VER) && defined(_CPPUNWIND)
   #define PROTOBUF_USE_EXCEPTIONS
