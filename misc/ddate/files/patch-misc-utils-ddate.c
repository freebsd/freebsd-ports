--- misc-utils/ddate.c.orig	Wed Jan 26 16:09:58 2005
+++ misc-utils/ddate.c	Wed Jan 26 16:10:30 2005
@@ -61,7 +61,7 @@
 #include <string.h>
 #include <time.h>
 #include <stdio.h>
-#include "nls.h"
+#include "../lib/nls.h"
 #include "../defines.h"		/* for util-linux-version */
 
 #ifndef __GNUC__
