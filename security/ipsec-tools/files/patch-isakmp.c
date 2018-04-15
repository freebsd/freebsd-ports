Index: src/racoon/isakmp.c
===================================================================
RCS file: /cvsroot/src/crypto/dist/ipsec-tools/src/racoon/isakmp.c,v
retrieving revision 1.75
retrieving revision 1.76
diff -p -u -r1.75 -r1.76
--- src/racoon/isakmp.c	9 Mar 2016 22:27:17 -0000	1.75
+++ src/racoon/isakmp.c	24 Jan 2017 19:23:56 -0000	1.76
@@ -1,4 +1,4 @@
-/*	$NetBSD: isakmp.c,v 1.75 2016/03/09 22:27:17 christos Exp $	*/
+/*	$NetBSD: isakmp.c,v 1.76 2017/01/24 19:23:56 christos Exp $	*/
 
 /* Id: isakmp.c,v 1.74 2006/05/07 21:32:59 manubsd Exp */
 
@@ -1077,6 +1077,7 @@ isakmp_ph1begin_i(rmconf, remote, local)
 		iph1->frag = 1;
 	else
 		iph1->frag = 0;
+	iph1->frag_last_index = 0;
 	iph1->frag_chain = NULL;
 #endif
 	iph1->approval = NULL;
@@ -1181,6 +1182,7 @@ isakmp_ph1begin_r(msg, remote, local, et
 #endif
 #ifdef ENABLE_FRAG
 	iph1->frag = 0;
+	iph1->frag_last_index = 0;
 	iph1->frag_chain = NULL;
 #endif
 	iph1->approval = NULL;
