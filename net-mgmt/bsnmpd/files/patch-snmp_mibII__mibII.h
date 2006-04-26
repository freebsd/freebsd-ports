--- snmp_mibII/mibII.h.orig	Mon Feb 27 13:03:15 2006
+++ snmp_mibII/mibII.h	Fri Apr 21 20:53:50 2006
@@ -55,6 +55,7 @@
 #include "snmpmod.h"
 #include "snmp_mibII.h"
 #include "mibII_tree.h"
+#include "support.h"
 
 /*
  * Interface list and flags.
@@ -76,6 +77,9 @@
 	uint64_t	hc_opackets;
 	uint64_t	hc_imcasts;
 	uint64_t	hc_ipackets;
+#ifndef HAVE_MIB_LINKSTATE
+	uint8_t 	pr_link_state;
+#endif
 };
 #define	MIBIF_PRIV(IFP) ((struct mibif_private *)((IFP)->private))
 
