--- conf.y.orig	Sun Sep 14 10:33:53 2003
+++ conf.y	Sun Nov  2 12:21:18 2003
@@ -2,7 +2,11 @@
 #include <stdio.h>
 #include <string.h>
 #include <unistd.h>
+#ifdef FREEBSD
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 #include <unistd.h>
 #include <sys/types.h>
 #include <signal.h>
