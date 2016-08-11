--- src/mod/applications/mod_avmd/avmd_fast_acosf.c.orig	2016-05-05 20:42:20 UTC
+++ src/mod/applications/mod_avmd/avmd_fast_acosf.c
@@ -23,6 +23,9 @@
 #include "avmd_fast_acosf.h"
 #include "avmd_options.h"

+#ifndef MAP_POPULATE
+#define MAP_POPULATE 0
+#endif

 typedef union {
     uint32_t i;
