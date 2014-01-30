--- ./lib/atscppapi/src/include/atscppapi/shared_ptr.h.orig	2013-12-05 22:07:48.000000000 +0000
+++ ./lib/atscppapi/src/include/atscppapi/shared_ptr.h	2014-01-27 08:45:49.000000000 +0000
@@ -25,7 +25,14 @@
 #ifndef ASTCPPAPI_SHARED_PTR_H_
 #define ASTCPPAPI_SHARED_PTR_H_
 
+#include <boost/config.hpp>
+#include <boost/tr1/detail/config.hpp>
+
+#ifndef BOOST_NO_CXX11_SMART_PTR
+#include <memory>
+#else
 #include <tr1/memory>
+#endif
 
 namespace atscppapi {
 
@@ -34,8 +41,11 @@
  * \todo Consider adding a simple macro to check if c++0x/11 is enabled
  * and if so change it to std::shared_ptr and #include <memory>s
  */
+#ifndef BOOST_NO_CXX11_SMART_PTR
+using std::shared_ptr;
+#else
 using std::tr1::shared_ptr;
-
+#endif
 } /* atscppapi */
 
 #endif /* SHARED_PTR_H_ */
