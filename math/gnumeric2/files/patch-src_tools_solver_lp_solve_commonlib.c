--- src/tools/solver/lp_solve/commonlib.c.orig	Wed Sep  1 23:20:25 2004
+++ src/tools/solver/lp_solve/commonlib.c	Wed Sep  1 23:25:07 2004
@@ -4,7 +4,7 @@
 #ifdef INTEGERTIME
 # include <time.h>
 #else
-# include <sys/timeb.h>
+# include <sys/time.h>
 #endif
 
 #include <stdlib.h>
@@ -282,10 +282,10 @@
 #elif defined CLOCKTIME
   return((double)clock()/CLOCKS_PER_SEC /* CLK_TCK */);
 #else
-  struct timeb buf;
+  struct timeval buf;
 
-  ftime(&buf);
-  return((double)buf.time+((double) buf.millitm)/1000.0);
+  gettimeofday(&buf, NULL);
+  return((double)buf.tv_sec+((double) buf.tv_usec)/1000.0);
 #endif
 }
 
