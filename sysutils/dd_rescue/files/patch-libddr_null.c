--- libddr_null.c.orig	2014-05-26 17:30:19.000000000 +0900
+++ libddr_null.c	2014-08-13 22:57:16.000000000 +0900
@@ -8,8 +8,10 @@
 
 #include "ddr_plugin.h"
 #include "ddr_ctrl.h"
+#include "ffs.h"
 #include <string.h>
 #include <stdlib.h>
+#include <stdint.h>
 
 /* fwd decl */
 extern ddr_plugin_t ddr_plug;
