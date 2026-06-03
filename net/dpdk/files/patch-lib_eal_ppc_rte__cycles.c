--- lib/eal/ppc/rte_cycles.c.orig
+++ lib/eal/ppc/rte_cycles.c
@@ -2,8 +2,8 @@
  * Copyright (C) IBM Corporation 2019.
  */
 
-#include <features.h>
 #ifdef __GLIBC__
+#include <features.h>
 #include <sys/platform/ppc.h>
 #elif RTE_EXEC_ENV_LINUX
 #include <string.h>
