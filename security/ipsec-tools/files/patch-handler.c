Index: src/racoon/handler.h
===================================================================
RCS file: /cvsroot/src/crypto/dist/ipsec-tools/src/racoon/handler.h,v
retrieving revision 1.25
retrieving revision 1.26
diff -p -u -r1.25 -r1.26
--- src/racoon/handler.h	17 Nov 2010 10:40:41 -0000	1.25
+++ src/racoon/handler.h	24 Jan 2017 19:23:56 -0000	1.26
@@ -1,4 +1,4 @@
-/*	$NetBSD: handler.h,v 1.25 2010/11/17 10:40:41 tteras Exp $	*/
+/*	$NetBSD: handler.h,v 1.26 2017/01/24 19:23:56 christos Exp $	*/
 
 /* Id: handler.h,v 1.19 2006/02/25 08:25:12 manubsd Exp */
 
@@ -141,6 +141,7 @@ struct ph1handle {
 #endif
 #ifdef ENABLE_FRAG
 	int frag;			/* IKE phase 1 fragmentation */
+	int frag_last_index;
 	struct isakmp_frag_item *frag_chain;	/* Received fragments */
 #endif
 
