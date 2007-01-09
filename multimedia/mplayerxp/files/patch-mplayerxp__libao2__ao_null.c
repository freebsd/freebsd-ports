--- mplayerxp/libao2/ao_null.c.orig	Thu Nov 30 15:32:02 2006
+++ mplayerxp/libao2/ao_null.c	Sun Dec 24 21:48:25 2006
@@ -1,7 +1,7 @@
-#include <stdint.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <limits.h>
+#include <sys/types.h>
 #include <sys/time.h>
 
 #include "config.h"
