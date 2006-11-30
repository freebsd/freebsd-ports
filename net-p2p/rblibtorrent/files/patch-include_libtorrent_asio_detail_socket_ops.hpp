--- include/libtorrent/asio/detail/socket_ops.hpp.original	Tue Oct 24 00:50:21 2006
+++ include/libtorrent/asio/detail/socket_ops.hpp	Wed Nov 29 14:40:02 2006
@@ -66,7 +66,7 @@
     socket_addr_len_type* addrlen)
 {
   set_error(0);
-#if defined(__MACH__) && defined(__APPLE__)
+#if defined(__MACH__) && defined(__APPLE__) || defined(__FreeBSD__)
   socket_type new_s = error_wrapper(::accept(s, addr, addrlen));
   if (new_s == invalid_socket)
     return new_s;
@@ -279,7 +279,7 @@
 #if defined(BOOST_WINDOWS) || defined(__CYGWIN__)
   return error_wrapper(::WSASocket(af, type, protocol, 0, 0,
         WSA_FLAG_OVERLAPPED));
-#elif defined(__MACH__) && defined(__APPLE__)
+#elif defined(__MACH__) && defined(__APPLE__) || defined(__FreeBSD__)
   socket_type s = error_wrapper(::socket(af, type, protocol));
   if (s == invalid_socket)
     return s;
@@ -561,7 +561,7 @@
 }
 
 #if defined(BOOST_WINDOWS) || defined(__CYGWIN__) \
-  || defined(__MACH__) && defined(__APPLE__)
+  || defined(__MACH__) && defined(__APPLE__) || defined(__FreeBSD__)
 
 // The following functions are only needed for emulation of getaddrinfo and
 // getnameinfo.
@@ -604,7 +604,7 @@
         buffer, buflength, error));
   *error = translate_netdb_error(*error);
   return retval;
-#elif defined(__MACH__) && defined(__APPLE__)
+#elif defined(__MACH__) && defined(__APPLE__) || defined(__FreeBSD__)
   (void)(buffer);
   (void)(buflength);
   hostent* retval = error_wrapper(::getipnodebyaddr(addr, length, af, error));
@@ -652,7 +652,7 @@
         buflength, error));
   *error = translate_netdb_error(*error);
   return retval;
-#elif defined(__MACH__) && defined(__APPLE__)
+#elif defined(__MACH__) && defined(__APPLE__) || defined(__FreeBSD__)
   (void)(buffer);
   (void)(buflength);
   hostent* retval = error_wrapper(::getipnodebyname(
@@ -679,7 +679,7 @@
 
 inline void freehostent(hostent* h)
 {
-#if defined(__MACH__) && defined(__APPLE__)
+#if defined(__MACH__) && defined(__APPLE__) || defined(__FreeBSD__)
   if (h)
     ::freehostent(h);
 #else
@@ -1372,7 +1372,7 @@
 }
 
 #endif // defined(BOOST_WINDOWS) || defined(__CYGWIN__)
-       //   || defined(__MACH__) && defined(__APPLE__)
+       //   || defined(__MACH__) && defined(__APPLE__) || defined(__FreeBSD__)
 
 inline int translate_addrinfo_error(int error)
 {
@@ -1425,7 +1425,7 @@
   int error = getaddrinfo_emulation(host, service, hints, result);
   return translate_addrinfo_error(error);
 # endif
-#elif defined(__MACH__) && defined(__APPLE__)
+#elif defined(__MACH__) && defined(__APPLE__) || defined(__FreeBSD__)
   int error = getaddrinfo_emulation(host, service, hints, result);
   return translate_addrinfo_error(error);
 #else
@@ -1453,7 +1453,7 @@
   }
   freeaddrinfo_emulation(ai);
 # endif
-#elif defined(__MACH__) && defined(__APPLE__)
+#elif defined(__MACH__) && defined(__APPLE__) || defined(__FreeBSD__)
   freeaddrinfo_emulation(ai);
 #else
   ::freeaddrinfo(ai);
@@ -1488,7 +1488,7 @@
       host, hostlen, serv, servlen, flags);
   return translate_addrinfo_error(error);
 # endif
-#elif defined(__MACH__) && defined(__APPLE__)
+#elif defined(__MACH__) && defined(__APPLE__) || defined(__FreeBSD__)
   using namespace std; // For memcpy.
   sockaddr_storage_type tmp_addr;
   memcpy(&tmp_addr, addr, addrlen);
