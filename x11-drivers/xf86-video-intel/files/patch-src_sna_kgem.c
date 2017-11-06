--- src/sna/kgem.c.orig	2017-02-28 20:52:19 UTC
+++ src/sna/kgem.c
@@ -29,6 +29,9 @@
 #include "config.h"
 #endif
 
+#define _WITH_GETLINE	/* to expose getline() in stdio.h on FreeBSD */
+#include <stdio.h>	/* for getline() */
+
 #include "sna.h"
 #include "sna_reg.h"
 
