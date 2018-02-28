--- src/lib/asiolink/io_service.h.orig	2017-10-05 13:00:03 UTC
+++ src/lib/asiolink/io_service.h
@@ -11,7 +11,12 @@
 
 namespace boost {
 namespace asio {
+#if BOOST_VERSION < 106600
     class io_service;
+#else
+    class io_context;
+    typedef io_context io_service;
+#endif
 }
 }
 
