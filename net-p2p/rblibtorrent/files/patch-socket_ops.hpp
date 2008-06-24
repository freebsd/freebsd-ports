--- include/libtorrent/asio/detail/socket_ops.hpp.orig	Wed Aug  8 03:43:42 2007
+++ include/libtorrent/asio/detail/socket_ops.hpp	Mon Sep 10 12:46:17 2007
@@ -715,7 +715,7 @@
   if (error)
     ec = translate_netdb_error(error);
   return retval;
-#elif defined(__MACH__) && defined(__APPLE__)
+#elif defined(__MACH__) && defined(__APPLE__) || defined(__FreeBSD__) 
   (void)(buffer);
   (void)(buflength);
   int error = 0;
