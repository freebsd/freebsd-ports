--- net/inet6.h.org	Mon Feb  4 17:51:39 2002
+++ net/inet6.h	Mon Feb  4 17:52:02 2002
@@ -44,7 +44,6 @@
 #define vic_inet6_h
 
 #ifdef HAVE_IPV6
-
 #include <sys/types.h>
 #ifdef WIN32
 //#include <winsock.h>
@@ -62,10 +61,23 @@
 }
 #else
 #include <netinet/in.h>
+#include <netinet6/in6.h>
 #endif
 #endif
 #ifndef WIN32
 #include <arpa/inet.h>
+#ifdef  _NETINET6_IN6_H_
+#ifndef IPV6_ADD_MEMBERSHIP
+#ifdef  IPV6_JOIN_GROUP
+#define IPV6_ADD_MEMBERSHIP IPV6_JOIN_GROUP
+#endif  /* IPV6_JOIN_GROUP      */
+#endif  /* IPV6_ADD_MEMBERSHIP  */
+#ifndef IPV6_DROP_MEMBERSHIP
+#ifdef  IPV6_LEAVE_GROUP
+#define IPV6_DROP_MEMBERSHIP IPV6_LEAVE_GROUP
+#endif  /* IPV6_LEAVE_GROUP     */
+#endif  /* IPV6_DROP_MEMBERSHIP */
+#endif  /* _NETINET6_IN6_H_     */
 #endif
 
 #include "config.h"
