--- utils.c.orig	2008-06-16 14:23:53.000000000 +0300
+++ utils.c	2013-08-24 04:23:19.000000000 +0300
@@ -23,10 +23,10 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
-#include <linux/types.h>
+#include <sys/types.h>
 #include <string.h>
 #include <fcntl.h>
-#include <wait.h>
+#include <sys/wait.h>
 #include <time.h>
 #include <limits.h>
 
