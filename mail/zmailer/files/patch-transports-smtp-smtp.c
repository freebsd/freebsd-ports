--- transports/smtp/smtp.c.orig	2008-02-13 12:43:13.000000000 +0100
+++ transports/smtp/smtp.c	2008-02-13 12:43:32.000000000 +0100
@@ -4214,8 +4214,10 @@
 
 
 #ifdef HAVE_OPENSSL
+#ifdef EPROTO
 	    if (SS->TLS.sslmode && err == EPROTO)
 	      break;
+#endif
 
 	    if (SS->TLS.sslmode && SS->TLS.wantreadwrite > 0) waitwr = 1;
 #endif /* - HAVE_OPENSSL */
