--- lib/eal/ppc/include/rte_cycles.h.orig
+++ lib/eal/ppc/include/rte_cycles.h
@@ -5,8 +5,8 @@
 #ifndef _RTE_CYCLES_PPC_64_H_
 #define _RTE_CYCLES_PPC_64_H_
 
-#include <features.h>
 #ifdef __GLIBC__
+#include <features.h>
 #include <sys/platform/ppc.h>
 #endif
 
