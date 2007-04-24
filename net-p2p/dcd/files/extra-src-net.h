--- src/net.h.orig	Wed Aug 30 22:09:02 2006
+++ src/net.h	Wed Apr 25 00:25:29 2007
@@ -13,6 +13,12 @@
 #if !defined( __vXhz__NET_H__INCLUDED__ )
 #define __vXhz__NET_H__INCLUDED__
 
+// Prior 600020 where no MSG_NOSIGNAL, so we will use SO_NOSIGPIPE
+#if defined (__FreeBSD__)
+	#ifndef MSG_NOSIGNAL
+		#define MSG_NOSIGNAL SO_NOSIGPIPE
+	#endif
+#endif
 
 
 void disttcp(userrec_t *usr, char *msg);
