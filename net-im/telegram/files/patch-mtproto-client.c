--- mtproto-client.c.orig	2014-10-02 12:07:49.000000000 +0200
+++ mtproto-client.c	2014-10-02 12:08:13.000000000 +0200
@@ -80,7 +80,7 @@
 #define MAX_NET_RES        (1L << 16)
 //extern int log_level;
 
-#ifndef HAVE___BUILTIN_BSWAP32
+#if !defined(HAVE___BUILTIN_BSWAP32) && !defined(__FreeBSD__) && !defined(__OpenBSD__)
 static inline unsigned __builtin_bswap32(unsigned x) {
   return ((x << 24) & 0xff000000 ) |
   ((x << 8) & 0x00ff0000 ) |
