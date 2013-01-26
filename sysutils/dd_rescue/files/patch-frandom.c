--- frandom.c.orig	2013-01-27 02:43:19.000000000 +0900
+++ frandom.c	2013-01-27 02:43:29.000000000 +0900
@@ -16,7 +16,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
-#include <asm/errno.h>
+#include <sys/errno.h>
 #include <unistd.h>
 #include <time.h>
 
