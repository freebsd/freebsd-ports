--- frandom.c.orig	2016-12-28 21:17:50 UTC
+++ frandom.c
@@ -16,7 +16,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
-#include <asm/errno.h>
+#include <sys/errno.h>
 #include <unistd.h>
 
 #ifdef HAVE_CONFIG_H
