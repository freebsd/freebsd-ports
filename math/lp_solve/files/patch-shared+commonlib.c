--- shared/commonlib.c.orig	Sat Mar 18 07:16:42 2006
+++ shared/commonlib.c	Sat Sep  2 21:01:39 2006
@@ -4,7 +4,7 @@
 #ifdef INTEGERTIME
 # include <time.h>
 #else
-# include <sys/timeb.h>
+# include <sys/time.h>
 #endif
 
 #include <stdlib.h>
@@ -673,10 +673,12 @@
 #elif defined CLOCKTIME
   return((double)clock()/CLOCKS_PER_SEC /* CLK_TCK */);
 #else
-  struct timeb buf;
+  struct timeval tv;
+  struct timezone tz;
+
+  gettimeofday(&tv, &tz);
+  return((double)tv.tv_sec+((double)tv.tv_usec)/1000000.0);
 
-  ftime(&buf);
-  return((double)buf.time+((double) buf.millitm)/1000.0);
 #endif
 }
 
