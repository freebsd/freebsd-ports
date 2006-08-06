--- include/libtorrent/asio/error.hpp	Sun Jun 11 18:51:03 2006
+++ include/libtorrent/asio/error.hpp	Sun Jul 23 13:49:29 2006
@@ -272,7 +272,7 @@
     default:
 #if defined(__sun) || defined(__QNX__)
       return strerror(code_);
-#elif defined(__MACH__) && defined(__APPLE__)
+#elif (defined(__MACH__) && defined(__APPLE__)) || defined(__FreeBSD__)
       try
       {
         char buf[256] = "";
