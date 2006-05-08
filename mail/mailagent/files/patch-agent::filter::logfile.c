--- agent/filter/logfile.c.orig Fri Mar 17 12:59:44 2006
+++ agent/filter/logfile.c      Fri Mar 17 13:02:25 2006
@@ -47,6 +47,12 @@
 #include <stdio.h>
 #include <sys/types.h>
 
+#ifdef I_STRING
+#include <string.h>
+#else
+#include <strings.h>
+#endif
+
 #ifdef I_TIME
 # include <time.h>
 #endif
