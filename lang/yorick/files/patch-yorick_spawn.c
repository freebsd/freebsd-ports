--- yorick/spawn.c.orig	Thu Mar  9 15:02:01 2006
+++ yorick/spawn.c	Thu Mar  9 15:02:07 2006
@@ -14,6 +14,7 @@
 #include "yio.h"
 
 #include <string.h>
+#include <unistd.h>
 
 /* FIXME -- things not in any .h file */
 extern void (*CleanUpForExit)(void);
