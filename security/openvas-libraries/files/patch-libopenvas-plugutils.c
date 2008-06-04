--- libopenvas/plugutils.c.orig	2008-04-26 22:03:11.000000000 +0900
+++ libopenvas/plugutils.c	2008-04-26 22:03:21.000000000 +0900
@@ -35,7 +35,7 @@
 #include <unistd.h>
 #include <errno.h>
 #include <signal.h>
-#include <wait.h>
+#include <sys/wait.h>
 #include <time.h>
 
 #include "arglists.h"
