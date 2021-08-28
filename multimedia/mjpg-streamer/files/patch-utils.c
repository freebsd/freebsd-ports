--- utils.c.orig	2021-02-20 17:47:40 UTC
+++ utils.c
@@ -23,13 +23,12 @@
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
-#include <linux/stat.h>
 #include <sys/stat.h>
 
 #include "utils.h"
