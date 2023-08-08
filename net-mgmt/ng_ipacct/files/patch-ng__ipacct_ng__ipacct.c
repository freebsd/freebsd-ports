--- ng_ipacct/ng_ipacct.c.orig	2022-09-13 09:05:22 UTC
+++ ng_ipacct/ng_ipacct.c
@@ -49,6 +49,9 @@ static const char rcs_id[] =
 #include <netinet/in_systm.h>
 #include <netinet/in.h>
 #include <netinet/in_pcb.h>
+#if __FreeBSD_version >= 1400039
+#include <netinet/in_pcb_var.h>
+#endif
 #include <netinet/ip.h>
 #include <netinet/ip_icmp.h>
 #include <netinet/ip_var.h>
