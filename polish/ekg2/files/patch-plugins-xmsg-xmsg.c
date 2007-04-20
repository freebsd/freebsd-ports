--- plugins/xmsg/xmsg.c.orig	Wed Apr  4 20:04:46 2007
+++ plugins/xmsg/xmsg.c	Wed Apr  4 20:07:39 2007
@@ -10,6 +10,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
+#include <limits.h>
 
 #include <sys/mman.h>
 #include <sys/stat.h>
