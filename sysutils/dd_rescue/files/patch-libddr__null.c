--- libddr_null.c.orig	2015-04-15 08:56:38 UTC
+++ libddr_null.c
@@ -8,8 +8,10 @@
 
 #include "ddr_plugin.h"
 #include "ddr_ctrl.h"
+#include "ffs.h"
 #include <string.h>
 #include <stdlib.h>
+#include <stdint.h>
 
 /* fwd decl */
 extern ddr_plugin_t ddr_plug;
