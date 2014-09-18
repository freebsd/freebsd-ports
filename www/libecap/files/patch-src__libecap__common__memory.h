--- src/libecap/common/memory.h.orig	2010-05-26 01:27:41.000000000 +0400
+++ src/libecap/common/memory.h	2014-09-12 15:06:36.000000000 +0400
@@ -4,14 +4,23 @@
 #define LIBECAP__COMMON_MEMORY_H
 
 #include <libecap/common/libecap.h>
+#if defined(_LIBCPP_VERSION)
+#include <memory>
+#else
 #include <tr1/memory>
+#endif
 
 // TODO: add support for boost pointers if std::tr1 is not available
 
 namespace libecap {
 
+#if defined(_LIBCPP_VERSION)
+using std::weak_ptr;
+using std::shared_ptr;
+#else
 using std::tr1::weak_ptr;
 using std::tr1::shared_ptr;
+#endif
 
 } // namespace libecap
 
