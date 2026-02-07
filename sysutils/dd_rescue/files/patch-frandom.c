--- frandom.c.orig	2023-02-23 21:51:27 UTC
+++ frandom.c
@@ -16,7 +16,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
-#include <asm/errno.h>
+#include <sys/errno.h>
 #include <unistd.h>
 //#include <assert.h>
 
