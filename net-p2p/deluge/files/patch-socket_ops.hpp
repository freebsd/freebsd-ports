--- libtorrent/include/libtorrent/asio/detail/socket_ops.hpp.orig	Sun May 27 17:11:11 2007
+++ libtorrent/include/libtorrent/asio/detail/socket_ops.hpp	Sun Jun 10 11:58:14 2007
@@ -63,7 +63,7 @@
     socket_addr_len_type* addrlen, asio::error_code& ec)
 {
   clear_error(ec);
-#if defined(__MACH__) && defined(__APPLE__)
+#if defined(__MACH__) && defined(__APPLE__) || defined(__FreeBSD__)
   socket_type new_s = error_wrapper(::accept(s, addr, addrlen), ec);
   if (new_s == invalid_socket)
     return new_s;
@@ -295,7 +295,7 @@
   }
 
   return s;
-#elif defined(__MACH__) && defined(__APPLE__)
+#elif defined(__MACH__) && defined(__APPLE__) || defined(__FreeBSD__) 
   socket_type s = error_wrapper(::socket(af, type, protocol), ec);
   if (s == invalid_socket)
     return s;
