--- util.c.orig	Thu Sep 25 06:37:57 1997
+++ util.c	Fri Jul 30 18:20:20 2004
@@ -123,11 +123,17 @@
 	{ "egp",  IPPROTO_EGP  },
 	{ "ospf", IPPROTO_OSPF },
 	{ "igmp", IPPROTO_IGMP },
+	{ "gre",  IPPROTO_GRE  },
+	{ "gif",  IPPROTO_IPIP },
+	{ "esp",  IPPROTO_ESP  },
 #ifdef	IPPROTO_GGP
 	{ "ggp",  IPPROTO_GGP  },
 #endif
 #ifdef	IPPROTO_ENCAP
 	{ "encap",IPPROTO_ENCAP},
+#endif
+#ifdef	IPPROTO_IPV6
+	{ "ipv6", IPPROTO_IPV6},
 #endif
 	{ "ip",   IPPROTO_IP   },
 	{ "raw",  IPPROTO_RAW  },
