--- ssl/d1_lib.c.orig	2015-02-09 23:29:07 UTC
+++ ssl/d1_lib.c
@@ -1,4 +1,4 @@
-/* $OpenBSD: d1_lib.c,v 1.26 2014/12/14 15:30:50 jsing Exp $ */
+/* $OpenBSD: d1_lib.c,v 1.27 2015/02/09 10:53:28 jsing Exp $ */
 /*
  * DTLS implementation written by Nagendra Modadugu
  * (nagendra@cs.stanford.edu) for the OpenSSL project 2005.
@@ -443,6 +443,9 @@ dtls1_listen(SSL *s, struct sockaddr *cl
 {
 	int ret;
 
+	/* Ensure there is no state left over from a previous invocation */
+	SSL_clear(s);
+
 	SSL_set_options(s, SSL_OP_COOKIE_EXCHANGE);
 	s->d1->listen = 1;
 
