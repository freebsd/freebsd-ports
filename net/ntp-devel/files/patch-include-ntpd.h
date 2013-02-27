--- include/ntpd.h.orig	2013-01-27 18:29:10.000000000 -0800
+++ include/ntpd.h	2013-02-26 21:53:41.000000000 -0800
@@ -523,7 +523,7 @@
 
 /* ntp_signd.c */
 #ifdef HAVE_NTP_SIGND
-extern void send_via_ntp_signd(struct recvbuf, int, keyid_t, int, 
+extern void send_via_ntp_signd(struct recvbuf *, int, keyid_t, int, 
 			       struct pkt *);
 #endif
 
