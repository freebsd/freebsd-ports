--- src/tools/cpulimit.c.orig	2015-05-06 10:55:30 UTC
+++ src/tools/cpulimit.c
@@ -19,6 +19,7 @@
 #include <unistd.h>
 #include <signal.h>
 #include <errno.h>
+#include <signal.h>
 #include <string.h>
 #include <sys/wait.h>
 
