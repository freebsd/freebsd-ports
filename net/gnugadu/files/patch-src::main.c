$FreeBSD$

--- src/orig.main.c	Tue Dec  4 00:09:20 2001
+++ src/main.c	Sun Dec 23 21:21:59 2001
@@ -32,7 +32,7 @@
 #include <sys/stat.h>
 #include <string.h>
 #include <signal.h>
-#include <wait.h>
+/* #include <wait.h> */
 
 #include "gg-types.h"
 #include "gg.h"
