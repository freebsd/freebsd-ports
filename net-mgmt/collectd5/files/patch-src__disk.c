--- src/disk.c.orig	2017-03-30 12:06:55.404638000 -0700
+++ src/disk.c	2017-03-30 12:06:01.167297000 -0700
@@ -26,6 +26,7 @@
 #include "common.h"
 #include "plugin.h"
 #include "utils_ignorelist.h"
+#include "utils_freebsd.h"
 
 #if HAVE_MACH_MACH_TYPES_H
 #include <mach/mach_types.h>
@@ -228,7 +229,7 @@
     ERROR("geom_gettree() failed, returned %d", rv);
     return (-1);
   }
-  rv = geom_stats_open();
+  rv = Geom_stats_open();
   if (rv != 0) {
     ERROR("geom_stats_open() failed, returned %d", rv);
     return (-1);
