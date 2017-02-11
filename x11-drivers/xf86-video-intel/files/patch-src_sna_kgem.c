--- src/sna/kgem.c.orig	2014-12-09 17:08:21.000000000 +0100
+++ src/sna/kgem.c	2015-11-19 00:06:27.883010000 +0100
@@ -29,6 +29,9 @@
 #include "config.h"
 #endif

+#define _WITH_GETLINE	/* to expose getline() in stdio.h on FreeBSD */
+#include <stdio.h>	/* for getline() */
+
 #include "sna.h"
 #include "sna_reg.h"

