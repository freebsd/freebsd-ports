--- include/libtorrent/asio/detail/socket_ops.hpp	Sun Jun 11 18:51:07 2006
+++ include/libtorrent/asio/detail/socket_ops.hpp	Sun Jul 23 13:54:19 2006
@@ -63,7 +63,8 @@
     socket_addr_len_type* addrlen)
 {
   set_error(0);
-#if defined(__MACH__) && defined(__APPLE__)
+//#if defined(__MACH__) && defined(__APPLE__)
+#if (defined(__MACH__) && defined(__APPLE__)) || defined(__FreeBSD__)
   socket_type new_s = error_wrapper(::accept(s, addr, addrlen));
   if (new_s == invalid_socket)
     return new_s;
@@ -266,7 +267,8 @@
 #if defined(BOOST_WINDOWS) || defined(__CYGWIN__)
   return error_wrapper(::WSASocket(af, type, protocol, 0, 0,
         WSA_FLAG_OVERLAPPED));
-#elif defined(__MACH__) && defined(__APPLE__)
+//#elif defined(__MACH__) && defined(__APPLE__)
+#elif (defined(__MACH__) && defined(__APPLE__)) || defined(__FreeBSD__)
   socket_type s = error_wrapper(::socket(af, type, protocol));
   if (s == invalid_socket)
     return s;
@@ -585,7 +587,7 @@
         buffer, buflength, error));
   *error = translate_netdb_error(*error);
   return retval;
-#elif defined(__MACH__) && defined(__APPLE__)
+#elif (defined(__MACH__) && defined(__APPLE__)) || defined(__FreeBSD__)
   (void)(buffer);
   (void)(buflength);
   hostent* retval = error_wrapper(::getipnodebyaddr(addr, length, af, error));
@@ -633,7 +635,7 @@
         buflength, error));
   *error = translate_netdb_error(*error);
   return retval;
-#elif defined(__MACH__) && defined(__APPLE__)
+#elif (defined(__MACH__) && defined(__APPLE__)) || defined(__FreeBSD__)
   (void)(buffer);
   (void)(buflength);
   hostent* retval = error_wrapper(::getipnodebyname(
@@ -660,7 +662,8 @@
 
 inline void freehostent(hostent* h)
 {
-#if defined(__MACH__) && defined(__APPLE__)
+//#if defined(__MACH__) && defined(__APPLE__)
+#if (defined(__MACH__) && defined(__APPLE__)) || defined(__FreeBSD__)
   if (h)
     ::freehostent(h);
 #else
@@ -1137,7 +1140,11 @@
       case NO_RECOVERY:
         return EAI_FAIL;
       case NO_DATA:
+#if defined(__FreeBSD__)
+        return EAI_NONAME;
+#else
         return EAI_NODATA;
+#endif
       default:
         return EAI_NONAME;
       }
@@ -1277,7 +1284,8 @@
   int error = getaddrinfo_emulation(host, service, hints, result);
   return translate_addrinfo_error(error);
 # endif
-#elif defined(__MACH__) && defined(__APPLE__)
+//#elif defined(__MACH__) && defined(__APPLE__)
+#elif (defined(__MACH__) && defined(__APPLE__)) || defined(__FreeBSD__)
   int error = getaddrinfo_emulation(host, service, hints, result);
   return translate_addrinfo_error(error);
 #else
@@ -1305,7 +1313,8 @@
   }
   freeaddrinfo_emulation(ai);
 # endif
-#elif defined(__MACH__) && defined(__APPLE__)
+//#elif defined(__MACH__) && defined(__APPLE__)
+#elif (defined(__MACH__) && defined(__APPLE__)) || defined(__FreeBSD__)
   freeaddrinfo_emulation(ai);
 #else
   ::freeaddrinfo(ai);
@@ -1466,7 +1475,8 @@
       host, hostlen, serv, servlen, flags);
   return translate_addrinfo_error(error);
 # endif
-#elif defined(__MACH__) && defined(__APPLE__)
+//#elif defined(__MACH__) && defined(__APPLE__)
+#elif (defined(__MACH__) && defined(__APPLE__)) || defined(__FreeBSD__)
   using namespace std; // For memcpy.
   sockaddr_storage_type tmp_addr;
   memcpy(&tmp_addr, addr, addrlen);
