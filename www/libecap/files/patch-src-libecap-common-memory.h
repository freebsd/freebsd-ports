--- src/libecap/common/memory.h.orig	2014-10-02 04:05:24 UTC
+++ src/libecap/common/memory.h
@@ -4,14 +4,28 @@
 #define LIBECAP__COMMON_MEMORY_H
 
 #include <libecap/common/libecap.h>
+#if defined(_LIBCPP_VERSION)
+#include <memory>
+#elif defined(__clang_major__) && __clang_major__ >= 13
+#include <memory>
+#else
 #include <tr1/memory>
+#endif
 
 // TODO: add support for boost pointers if std::tr1 is not available
 
 namespace libecap {
 
+#if defined(_LIBCPP_VERSION)
+using std::weak_ptr;
+using std::shared_ptr;
+#elif defined(__clang_major__) && __clang_major__ >= 13
+using std::weak_ptr;
+using std::shared_ptr;
+#else
 using std::tr1::weak_ptr;
 using std::tr1::shared_ptr;
+#endif
 
 } // namespace libecap
 
