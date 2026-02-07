--- rawsend.c.orig	2015-04-28 22:22:02 UTC
+++ rawsend.c
@@ -118,9 +118,9 @@ raw_send_from_to (s, msg, msglen, saddr_generic, daddr
   /* Depending on the target platform, te ip_off and ip_len fields
      should be in either host or network byte order.  Usually
      BSD-derivatives require host byte order, but at least OpenBSD
-     since version 2.1 uses network byte order.  Linux uses network
-     byte order for all IP header fields. */
-#if defined (__linux__) || (defined (__OpenBSD__) && (OpenBSD > 199702))
+     since version 2.1 and FreeBSD since 11.0 use network byte
+     order.  Linux uses network byte order for all IP header fields. */
+#if defined (__linux__) || (defined (__OpenBSD__) && (OpenBSD > 199702)) || (defined (__FreeBSD_version) && (__FreeBSD_version > 1100030))
   ih.ip_len = htons (length);
   ih.ip_off = htons (0);
 #else 
