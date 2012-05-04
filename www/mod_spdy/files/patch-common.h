--- third_party/protobuf/src/google/protobuf/stubs/common.h	2012-03-31 16:29:08.772785000 +0900
+++ third_party/protobuf/src/google/protobuf/stubs/common.h	2012-03-31 16:59:06.012795843 +0900
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
