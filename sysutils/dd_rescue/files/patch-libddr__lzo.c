--- libddr_lzo.c.orig	2024-08-22 17:41:01 UTC
+++ libddr_lzo.c
@@ -13,6 +13,7 @@
 #define _LARGEFILE64_SOURCE 1
 #define _FILE_OFFSET_BITS 64
 
+#include "config.h"
 #include "ddr_plugin.h"
 #include "ddr_ctrl.h"
 #include "mybasename.h"
