--- repair/progress.c.orig	2015-07-24 04:28:04 UTC
+++ repair/progress.c
@@ -1,4 +1,5 @@
 
+#include <inttypes.h>
 #include <libxfs.h>
 #include "globals.h"
 #include "progress.h"
