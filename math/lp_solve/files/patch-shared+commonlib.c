--- shared/commonlib.c.orig	2016-05-06 09:25:24 UTC
+++ shared/commonlib.c
@@ -6,7 +6,7 @@
 #elif defined EnhTime
 # include <windows.h>
 #else
-# include <sys/timeb.h>
+# include <sys/time.h>
 #endif
 
 #include <stdlib.h>
@@ -844,10 +844,12 @@ double timeNow(void)
   }
   return( timeBase + (double) now.QuadPart/(double) freq.QuadPart );
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
 
