--- deps/usrsctp/usrsctplib/user_recv_thread.c.orig	2021-09-21 17:22:53 UTC
+++ deps/usrsctp/usrsctplib/user_recv_thread.c
@@ -58,7 +58,7 @@
 #endif
 #if defined(HAVE_NET_ROUTE_H)
 # include <net/route.h>
-#elif defined(__APPLE__)
+#elif defined(__APPLE__)  || defined(__DragonFly__) || defined(__FreeBSD__)
 /* Apple SDKs for iOS, tvOS, watchOS, etc. don't ship this header */
 # define RTM_NEWADDR 0xc
 # define RTM_DELADDR 0xd
