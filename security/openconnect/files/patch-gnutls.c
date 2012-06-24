--- ./gnutls.c.orig	2012-06-24 07:29:27.000000000 -0400
+++ ./gnutls.c	2012-06-24 07:29:43.000000000 -0400
@@ -239,7 +239,7 @@
 /* For systems that don't support O_CLOEXEC, just don't bother.
    It's not open for long anyway. */
 #ifndef O_CLOEXEC
-#define O_CLOEXEC
+#define O_CLOEXEC 0
 #endif
 
 static int load_datum(struct openconnect_info *vpninfo,
