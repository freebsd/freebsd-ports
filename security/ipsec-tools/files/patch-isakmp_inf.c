Index: src/racoon/isakmp_inf.c
===================================================================
RCS file: /cvsroot/src/crypto/dist/ipsec-tools/src/racoon/isakmp_inf.c,v
retrieving revision 1.50
retrieving revision 1.51
diff -p -u -r1.50 -r1.51
--- src/racoon/isakmp_inf.c	12 Apr 2013 09:53:10 -0000	1.50
+++ src/racoon/isakmp_inf.c	24 Jan 2017 19:23:56 -0000	1.51
@@ -1,4 +1,4 @@
-/*	$NetBSD: isakmp_inf.c,v 1.50 2013/04/12 09:53:10 tteras Exp $	*/
+/*	$NetBSD: isakmp_inf.c,v 1.51 2017/01/24 19:23:56 christos Exp $	*/
 
 /* Id: isakmp_inf.c,v 1.44 2006/05/06 20:45:52 manubsd Exp */
 
@@ -720,6 +720,7 @@ isakmp_info_send_nx(isakmp, remote, loca
 #endif
 #ifdef ENABLE_FRAG
 	iph1->frag = 0;
+	iph1->frag_last_index = 0;
 	iph1->frag_chain = NULL;
 #endif
 
