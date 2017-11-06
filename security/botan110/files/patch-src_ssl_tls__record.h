--- src/ssl/tls_record.h.orig	2016-04-28 13:27:08 UTC
+++ src/ssl/tls_record.h
@@ -17,8 +17,15 @@
 
 #if defined(BOTAN_USE_STD_TR1)
 
-#if defined(BOTAN_BUILD_COMPILER_IS_MSVC)
+#if defined(_LIBCPP_VERSION) || defined(BOTAN_BUILD_COMPILER_IS_MSVC)
     #include <functional>
+    #if defined(_LIBCPP_VERSION)
+    namespace std {
+      namespace tr1 {
+        using std::function;
+      }
+    }
+    #endif
 #else
     #include <tr1/functional>
 #endif
@@ -31,7 +38,11 @@
 
 namespace Botan {
 
+#if defined(_LIBCPP_VERSION)
+using namespace std::placeholders;
+#else
 using namespace std::tr1::placeholders;
+#endif
 
 /**
 * TLS Record Writer
