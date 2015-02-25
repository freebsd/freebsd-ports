--- src/file/mmc_device_linux.c.orig	2015-01-29 11:40:32.000000000 +0100
+++ src/file/mmc_device_linux.c	2015-01-29 11:42:00.000000000 +0100
@@ -32,6 +32,7 @@
 #include "util/strutl.h"
 
 #include <stdlib.h>
+#include <stdio.h>
 #include <string.h>
 #include <unistd.h>
 #include <fcntl.h>
@@ -180,8 +181,8 @@
         } else {
             BD_DEBUG(DBG_MMC | DBG_CRIT, "Error opening /proc/mounts\n");
         }
-#endif
     }
+#endif
 
     if (fd >= 0) {
         dev = calloc(1, sizeof(MMCDEV));
