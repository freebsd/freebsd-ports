--- unix/tclUnixSock.c.orig	2017-09-04 07:52:03 UTC
+++ unix/tclUnixSock.c
@@ -713,10 +713,14 @@ IPv6AddressNeedsNumericRendering(
      * at least some versions of OSX.
      */
 
+#if defined (__clang__) || ((__GNUC__) && ((__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ > 5))))
 #pragma GCC diagnostic push
 #pragma GCC diagnostic ignored "-Wstrict-aliasing"
+#endif
     if (!IN6_IS_ADDR_V4MAPPED(&addr)) {
+#if defined (__clang__) || ((__GNUC__) && ((__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ > 5))))
 #pragma GCC diagnostic pop
+#endif
         return 0;
     }
 
