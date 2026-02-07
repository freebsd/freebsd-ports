--- pee.c.orig	2017-12-31 16:02:11 UTC
+++ pee.c
@@ -2,6 +2,7 @@
 #include <stdio.h>
 #include <unistd.h>
 #include <string.h>
+#include <signal.h>
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <errno.h>
