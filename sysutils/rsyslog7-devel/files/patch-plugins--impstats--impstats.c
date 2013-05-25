--- plugins/impstats/impstats.c.ori	2013-05-24 20:36:41.000000000 -0600
+++ plugins/impstats/impstats.c	2013-05-24 20:36:56.000000000 -0600
@@ -39,6 +39,7 @@
 #include "glbl.h"
 #include "statsobj.h"
 #include "prop.h"
+#include <sys/stat.h>
 
 MODULE_TYPE_INPUT
 MODULE_TYPE_NOKEEP
