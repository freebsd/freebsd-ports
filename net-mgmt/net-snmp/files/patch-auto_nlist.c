--- agent/auto_nlist.c.orig	Mon Jan 24 09:11:07 2005
+++ agent/auto_nlist.c	Mon Jan 24 09:11:24 2005
@@ -21,10 +21,6 @@
 #include <kvm.h>
 #endif
 
-#if HAVE_DMALLOC_H
-#include <dmalloc.h>
-#endif
-
 #include <net-snmp/agent/auto_nlist.h>
 #include "autonlist.h"
 #include "kernel.h"
