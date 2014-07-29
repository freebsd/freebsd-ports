--- ./modules/dummynet/dummynet.c.orig	2013-03-29 14:22:50.000000000 +0000
+++ ./modules/dummynet/dummynet.c	2014-07-29 09:30:53.000000000 +0100
@@ -57,15 +57,19 @@
 
 	if (ip_dn_io_ptr != NULL)
 	{
+#if __FreeBSD__ < 10
 		SET_NET_IPLEN(mtod(*mb, struct ip *));
+#endif
 		if (mtod(*mb, struct ip *)->ip_v == 4)
 			ret = ip_dn_io_ptr(mb, dir, &ipfw_args);
 		else if (mtod(*mb, struct ip *)->ip_v == 6)
 			ret = ip_dn_io_ptr(mb, dir | PROTO_IPV6, &ipfw_args);
+#if __FreeBSD__ < 10
 		if ((*mb) != NULL)
 		{
 			SET_HOST_IPLEN(mtod(*mb, struct ip *));
 		}
+#endif
 	}
 	return ret;
 }
