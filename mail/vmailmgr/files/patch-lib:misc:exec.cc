--- lib/misc/exec.cc.orig	Mon Feb  2 14:31:16 2004
+++ lib/misc/exec.cc	Mon Feb  2 14:31:41 2004
@@ -17,6 +17,7 @@
 #include <config.h>
 #include <errno.h>
 #include <stdlib.h>
+#include <string.h>
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <sys/wait.h>
