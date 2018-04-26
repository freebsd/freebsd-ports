--- smtpd/mda.c.orig	2016-05-13 02:56:04.000000000 +1000
+++ smtpd/mda.c	2018-04-26 10:28:45.373358000 +1000
@@ -274,7 +274,7 @@
 					 * if any
 					 */
 					n = iobuf_fqueue(&s->iobuf,
-					    "Return-Path: %s\n"
+					    "Return-Path: <%s>\n"
 					    "Delivered-To: %s\n",
 					    e->sender,
 					    e->rcpt ? e->rcpt : e->dest);
