--- ats_cc/kern.c.orig	2009-04-11 15:20:31.000000000 +0200
+++ ats_cc/kern.c	2009-04-11 15:00:04.000000000 +0200
@@ -427,7 +427,7 @@
 		err(1, NULL);
 
 	uarg->op = sig;
-	memcpy(uarg->data, msg->b_rptr, uni_msg_len(msg));
+	memcpy(uarg + 1, msg->b_rptr, uni_msg_len(msg));
 
 	if ((ret = NgSendData(dsock, user->hook, (const u_char *)uarg,
 	    sizeof(*uarg) + uni_msg_len(msg))) == -1)
