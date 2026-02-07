--- wmmaiload/dockapp.c.orig	2022-11-07 08:58:34 UTC
+++ wmmaiload/dockapp.c
@@ -26,6 +26,7 @@
 #include "dockapp.h"
 #include <sys/time.h>
 #include <sys/types.h>
+#include <stdlib.h>
 #include <unistd.h>
 
 #define WINDOWED_SIZE_W 64
