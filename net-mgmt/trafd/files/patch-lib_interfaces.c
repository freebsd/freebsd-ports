--- lib/interfaces.c.orig	2002-11-27 08:40:33.000000000 -0500
+++ lib/interfaces.c	2009-05-29 14:20:33.000000000 -0400
@@ -32,7 +32,9 @@
 #include <netinet/in.h>
 #include <net/ethernet.h>
 #include <net/ppp_defs.h>
+#ifdef CSLIP
 #include <net/slip.h>
+#endif
 #include <netinet/if_ether.h>
 #include <netinet/in_systm.h>
 #include <netinet/ip.h>
@@ -60,8 +62,10 @@
 
 static struct printer printers[] = {
 		{ ether_if_print,       DLT_EN10MB },
+#ifdef CSLIP
 		{ sl_if_print,          DLT_SLIP },
 		{ sl_bsdos_if_print,    DLT_SLIP_BSDOS },
+#endif
 		{ ppp_if_print,         DLT_PPP },
 		{ ppp_bsdos_if_print,   DLT_PPP_BSDOS },
 		{ null_if_print,        DLT_NULL },
@@ -232,6 +236,8 @@
 	processing_ip(p, length);
 }
 
+#ifdef CSLIP
+
 /* XXX BSD/OS 2.1 compatibility */
 #if !defined(SLIP_HDRLEN) && defined(SLC_BPFHDR)
 #define SLIP_HDRLEN SLC_BPFHDR
@@ -288,3 +294,4 @@
 	processing_ip(p + SLIP_HDRLEN, length);
 
 }
+#endif
