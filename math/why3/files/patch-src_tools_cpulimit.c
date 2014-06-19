--- src/tools/cpulimit.c.orig	2014-03-14 15:01:03.000000000 +0000
+++ src/tools/cpulimit.c
@@ -18,6 +18,7 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <errno.h>
+#include <signal.h>
 #include <string.h>
 #include <sys/wait.h>
 
