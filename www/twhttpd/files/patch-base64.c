--- base64.c.orig	Sun Feb  4 20:11:49 2007
+++ base64.c	Sun Feb  4 20:11:59 2007
@@ -40,6 +40,7 @@
 #include <stdio.h>
 #include <errno.h>
 #include <stdlib.h>
+#include <string.h>
 #include <unistd.h>
 
 #include "config.h"
