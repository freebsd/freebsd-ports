--- scanlogd.c.orig	Mon May 10 13:32:49 2004
+++ scanlogd.c	Mon May 10 13:33:10 2004
@@ -11,6 +11,7 @@
 
 #define _BSD_SOURCE
 #include <stdio.h>
+#include <stdlib.h>
 #include <unistd.h>
 #include <signal.h>
 #include <string.h>
