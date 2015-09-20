--- common/slp_socket.h.orig	2015-09-20 22:43:10 UTC
+++ common/slp_socket.h
@@ -103,7 +103,8 @@ const char * inet_ntop(int af, const voi
 # include <net/if.h>
 # include <net/if_arp.h>
 # include <netdb.h>
-#if defined(LINUX) || defined (DARWIN)
+# include <netinet/in.h>
+#if defined(LINUX) || defined (DARWIN) || defined (__FreeBSD__)
 # include <ifaddrs.h>
 #endif
 
