--- libddr_null.c.orig	2014-06-29 00:55:34.000000000 +0900
+++ libddr_null.c	2014-06-29 00:56:42.000000000 +0900
@@ -10,6 +10,7 @@
 #include "ddr_ctrl.h"
 #include <string.h>
 #include <stdlib.h>
+#include <stdint.h>
 
 /* fwd decl */
 extern ddr_plugin_t ddr_plug;
