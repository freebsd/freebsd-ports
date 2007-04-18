--- include/libtorrent/asio/detail/socket_ops.hpp.orig	Wed Mar  7 15:04:00 2007
+++ include/libtorrent/asio/detail/socket_ops.hpp	Mon Apr 16 16:05:17 2007
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
@@ -654,7 +654,7 @@
   if (error)
     ec = translate_netdb_error(error);
   return retval;
-#elif defined(__MACH__) && defined(__APPLE__)
+#elif defined(__MACH__) && defined(__APPLE__) || defined(__FreeBSD__)
   (void)(buffer);
   (void)(buflength);
   int error = 0;
@@ -708,7 +708,7 @@
   if (error)
     ec = translate_netdb_error(error);
   return retval;
-#elif defined(__MACH__) && defined(__APPLE__)
+#elif defined(__MACH__) && defined(__APPLE__) || defined(__FreeBSD__)
   (void)(buffer);
   (void)(buflength);
   int error = 0;
@@ -739,7 +739,7 @@
 
 inline void freehostent(hostent* h)
 {
-#if defined(__MACH__) && defined(__APPLE__)
+#if defined(__MACH__) && defined(__APPLE__) || defined(__FreeBSD__)
   if (h)
     ::freehostent(h);
 #else
