--- ntop.h.orig	Mon Aug  1 12:07:39 2005
+++ ntop.h	Mon Aug  1 12:08:13 2005
@@ -447,7 +447,7 @@
 #endif
 
 #ifndef EMBEDDED
-#include "rrd.h"
+#include "myrrd/rrd.h"
 #endif
 
 #ifdef HAVE_GETOPT_H
