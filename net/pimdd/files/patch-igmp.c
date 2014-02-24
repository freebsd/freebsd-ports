--- igmp.c.orig	2014-01-22 00:05:49.560452946 +0100
+++ igmp.c	2014-01-22 00:06:57.098508699 +0100
@@ -168,7 +168,11 @@
 #ifdef RAW_INPUT_IS_RAW
     ipdatalen = ntohs(ip->ip_len) - iphdrlen;
 #else
+ #if __FreeBSD_version >= 1000000
+	ipdatalen = ip->ip_len - iphdrlen;
+ #else
     ipdatalen = ip->ip_len;
+ #endif
 #endif
     if (iphdrlen + ipdatalen != recvlen) {
 	log(LOG_WARNING, 0,
