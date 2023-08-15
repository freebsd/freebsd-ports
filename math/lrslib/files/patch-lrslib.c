--- lrslib.c.orig	2022-03-10 09:42:46 UTC
+++ lrslib.c
@@ -32,6 +32,8 @@
 #include <limits.h>
 #include <libgen.h>
 
+#include <libgen.h> // for basename(3)
+
 #include "lrsrestart.h"
 #include "lrslib.h"
 
@@ -75,7 +77,7 @@ static void ptimes (void);
 static double get_time(void);
 #endif
 
-char *basename(char *path);
+//char *basename(char *path);
 
 /*******************************/
 /* signals handling            */
