--- sendip.c.orig	2004-04-09 23:38:56 UTC
+++ sendip.c
@@ -48,12 +48,12 @@ void send_ip (char* src, char *dst, char
 	ip->ihl		= (IPHDR_SIZE + optlen + 3) >> 2;
 	ip->tos		= ip_tos;
 
-#if defined OSTYPE_FREEBSD || defined OSTYPE_NETBSD || defined OSTYPE_BSDI
-/* FreeBSD */
+#if defined OSTYPE_NETBSD || defined OSTYPE_BSDI
 /* NetBSD */
 	ip->tot_len	= packetsize;
 #else
 /* Linux */
+/* FreeBSD */
 /* OpenBSD */
 	ip->tot_len	= htons(packetsize);
 #endif
@@ -73,13 +73,13 @@ void send_ip (char* src, char *dst, char
 			htons((unsigned short) src_id);
 	}
 
-#if defined OSTYPE_FREEBSD || defined OSTYPE_NETBSD | defined OSTYPE_BSDI
-/* FreeBSD */
+#if defined OSTYPE_NETBSD | defined OSTYPE_BSDI
 /* NetBSD */
 	ip->frag_off	|= more_fragments;
 	ip->frag_off	|= fragoff >> 3;
 #else
 /* Linux */
+/* FreeBSD */
 /* OpenBSD */
 	ip->frag_off	|= htons(more_fragments);
 	ip->frag_off	|= htons(fragoff >> 3); /* shift three flags bit */
