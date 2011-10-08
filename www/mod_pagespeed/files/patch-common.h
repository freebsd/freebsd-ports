--- third_party/protobuf/src/google/protobuf/stubs/common.h.orig
+++ third_party/protobuf/src/google/protobuf/stubs/common.h
@@ -47,6 +47,8 @@
 #elif !defined(_MSC_VER)
 #include <stdint.h>
 #endif
+#undef major
+#undef minor
 
 #if defined(_WIN32) && defined(GetMessage)
 // Allow GetMessage to be used as a valid method name in protobuf classes.
