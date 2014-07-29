--- protocols/ip/nd_ip.c.orig	Sun Oct 13 21:33:19 2002
+++ protocols/ip/nd_ip.c	Sun Oct 13 21:34:05 2002
@@ -102,7 +102,7 @@
   { N_("Low delay"),         N_("Minimize delay"),       IPTOS_LOWDELAY,    nd_ip_tos_value_cb },
   { N_("Throughput"),        N_("Maximize throughput"),  IPTOS_THROUGHPUT,  nd_ip_tos_value_cb },
   { N_("Reliability"),       N_("Maximize reliability"), IPTOS_RELIABILITY, nd_ip_tos_value_cb },
-  { N_("Low cost"),          N_("Minimize cost"),        IPTOS_LOWCOST,     nd_ip_tos_value_cb },
+  { N_("Low cost"),          N_("Minimize cost"),        IPTOS_MINCOST,     nd_ip_tos_value_cb },
   { N_("None"),              N_("Clear all bits"),       0,                 nd_ip_tos_value_cb },
   { N_("Custom"),            N_("Custom ToS value"),     -1,                nd_ip_tos_custom_cb },
   { NULL, NULL, 0, NULL}
