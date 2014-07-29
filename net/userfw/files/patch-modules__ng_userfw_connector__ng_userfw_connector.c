--- ./modules/ng_userfw_connector/ng_userfw_connector.c.orig	2013-03-29 14:22:50.000000000 +0000
+++ ./modules/ng_userfw_connector/ng_userfw_connector.c	2014-07-29 09:30:53.000000000 +0100
@@ -196,7 +196,9 @@
 	if (hookp == NULL)
 		return ESRCH;
 
+#if __FreeBSD__ < 10
 	SET_NET_IPLEN(mtod(mb, struct ip *));
+#endif
 	NG_SEND_DATA_ONLY(err, hookp, mb);
 
 	return err;
