--- src/unix_random.c.orig	Sun Feb 16 21:27:45 2003
+++ src/unix_random.c	Sun Mar  2 10:18:35 2003
@@ -36,9 +36,9 @@
 #endif
 
 #include <sys/types.h>
+#include <sys/time.h>
 #include <sys/resource.h>
 #include <sys/stat.h>
-#include <sys/time.h>
 
 #include "randomness.h"
 
