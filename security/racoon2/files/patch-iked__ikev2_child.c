--- iked/ikev2_child.c.orig	2008-09-10 01:30:58.000000000 -0700
+++ iked/ikev2_child.c	2014-10-22 23:33:18.140601874 -0700
@@ -1171,7 +1171,7 @@
 	 * used to do update or add.
 	 */
 	param->flags = 0;
-	if (child_sa->is_initiator)
+	if (child_sa->is_initiator && child_sa->preceding_satype == 0)
 		param->flags |= PFK_FLAG_NOPORTS;
 
 	param->wsize = ikev2_ipsec_window_size;
