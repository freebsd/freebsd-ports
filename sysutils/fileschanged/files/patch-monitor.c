--- src/monitor.c.orig Mon Feb 23 02:17:30 2004
+++ src/monitor.c Wed May 19 18:30:54 2004
@@ -2,7 +2,9 @@
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
+#if !defined(__FreeBSD__)
 #include <sys/select.h>
+#endif
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <time.h>
