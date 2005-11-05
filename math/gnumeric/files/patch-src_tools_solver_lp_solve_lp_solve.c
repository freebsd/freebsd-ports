--- src/tools/solver/lp_solve/lp_solve.c.orig	Sun Aug 28 16:01:54 2005
+++ src/tools/solver/lp_solve/lp_solve.c	Sun Aug 28 16:04:24 2005
@@ -7,7 +7,7 @@
 #include <stdlib.h>
 #include <errno.h>
 #include <time.h>
-#include <sys/timeb.h>
+#include <sys/time.h>
 
 #define LoadInverseLib FALSE
 #define LoadLanguageLib FALSE
@@ -15891,10 +15891,10 @@ static double timeNow(void)
 #elif defined CLOCKTIME
   return((double)clock()/CLOCKS_PER_SEC /* CLK_TCK */);
 #else
-  struct timeb buf;
+  struct timeval tp;
 
-  ftime(&buf);
-  return((double)buf.time+((double) buf.millitm)/1000.0);
+  (void)gettimeofday(&tp, NULL);
+  return((double)tp.tv_sec+((double) (tp.tv_usec*1000))/1000.0);
 #endif
 }
 
