--- socket_include.h.orig	Sat Jan 15 14:48:57 2005
+++ socket_include.h	Sat Jan 15 22:31:09 2005
@@ -1,10 +1,31 @@
 #ifndef _SOCKET_INCLUDE_H
 #define _SOCKET_INCLUDE_H
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #ifdef SOLARIS 
 // ----------------------------------------
 // Solaris
 typedef unsigned short port_t;
+
+#elif defined __FreeBSD__
+// ----------------------------------------
+// FreeBSD
+# if __FreeBSD_version >= 400014
+#  define s6_addr16 __u6_addr.__u6_addr16
+#  if !defined(MSG_NOSIGNAL)
+#    define MSG_NOSIGNAL 0
+#  endif
+#  include <netinet/in.h>
+typedef	in_addr_t ipaddr_t;
+typedef	in_port_t port_t;
+#  define IPV6_ADD_MEMBERSHIP IPV6_JOIN_GROUP
+#  define IPV6_DROP_MEMBERSHIP IPV6_LEAVE_GROUP
+# else
+#  error FreeBSD versions prior to 400014 does not support ipv6
+# endif
 
 #elif defined MACOSX 
 // ----------------------------------------
