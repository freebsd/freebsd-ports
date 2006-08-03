--- common/netio/pub/platform/unix/sockio.h	Thu Jul  8 21:46:54 2004
+++ common/netio/pub/platform/unix/sockio.h	Sat Jul  1 14:30:54 2006
@@ -93,7 +93,8 @@
 #if defined (_AIX42)
 #define HX_SOCKLEN_T size_t
-#elif defined(_AIX43) || defined(_FREEBSD5) || defined(_FREEBSD4) || defined(_OPENBSD) ||defined(_NETBSD) || defined(_LINUX) || (defined (__GNUC__) && defined(_SOLARIS))
+#elif defined(_AIX43) || defined(__FreeBSD__) || defined(_OPENBSD) ||defined(_NETBSD) || defined(_LINUX) || (defined (__GNUC__) && defined(_SOLARIS))
 #define HX_SOCKLEN_T socklen_t
 #else
+#error "socklen_t misdefined"
 #define HX_SOCKLEN_T int
 #endif
@@ -306,5 +307,5 @@
 
     HX_SOCKLEN_T temp_addr = *addr_len;
-    int ret = ::getsockname(sock, (HX_SOCKADDR_T*)addr, (HX_SOCKLEN_T *)&temp_addr);
+    int ret = ::getsockname(sock, (HX_SOCKADDR_T*)addr, &temp_addr);
     *addr_len = temp_addr;
 #ifdef _LINUX
