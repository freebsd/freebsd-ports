--- src/gskdaemonize.c.orig	Sat Mar  5 02:29:09 2005
+++ src/gskdaemonize.c	Sun May 15 01:59:28 2005
@@ -2,6 +2,7 @@
 #include <stdio.h>
 #include <errno.h>
 #include <sys/wait.h>
+#include <signal.h>
 #include <string.h>
 #include <stdlib.h>
 #include <unistd.h>
