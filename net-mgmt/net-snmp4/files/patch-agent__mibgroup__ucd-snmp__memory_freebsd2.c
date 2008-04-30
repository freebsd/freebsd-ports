--- agent/mibgroup/ucd-snmp/memory_freebsd2.c.orig	2008-04-30 11:37:04.000000000 +0000
+++ agent/mibgroup/ucd-snmp/memory_freebsd2.c	2008-04-30 11:36:43.000000000 +0000
@@ -30,6 +30,7 @@
 #else
 #include <vm/vm_param.h>
 #endif
+#include <vm/swap_pager.h>
  
 #include <time.h>
 #include <nlist.h>
