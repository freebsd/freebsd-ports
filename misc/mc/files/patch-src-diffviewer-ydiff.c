--- src/diffviewer/ydiff.c.orig	2010-05-05 21:33:16.000000000 +0300
+++ src/diffviewer/ydiff.c	2010-05-06 11:33:06.000000000 +0300
@@ -31,6 +31,7 @@
 #include <stdlib.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <sys/wait.h>
 
 #include "lib/global.h"
 #include "lib/tty/tty.h"
