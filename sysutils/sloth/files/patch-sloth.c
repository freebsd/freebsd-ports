--- sloth.c.orig	Sat May 11 01:25:43 2002
+++ sloth.c	Sat May 11 01:25:49 2002
@@ -23,7 +23,7 @@
  */
 
 #include <stdio.h>
-#include <wait.h>
+#include <sys/wait.h>
 #include <signal.h>
 #include <sys/types.h>
 #include <sys/time.h>
