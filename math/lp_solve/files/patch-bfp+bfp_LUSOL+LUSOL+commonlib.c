--- bfp/bfp_LUSOL/LUSOL/commonlib.c.org	Sat Mar 18 07:14:02 2006
+++ bfp/bfp_LUSOL/LUSOL/commonlib.c	Sat Sep  2 20:53:52 2006
@@ -4,7 +4,7 @@
 #ifdef INTEGERTIME
 # include <time.h>
 #else
-# include <sys/timeb.h>
+#include <sys/time.h>
 #endif
 
 #include <stdlib.h>
@@ -673,10 +673,11 @@
 #elif defined CLOCKTIME
   return((double)clock()/CLOCKS_PER_SEC /* CLK_TCK */);
 #else
-  struct timeb buf;
+  struct timeval tv;
+  struct timezone tz;
 
-  ftime(&buf);
-  return((double)buf.time+((double) buf.millitm)/1000.0);
+  gettimeofday(&tv, &tz);
+  return((double)tv.tv_sec+((double)tv.tv_usec)/1000.0);
 #endif
 }
 
