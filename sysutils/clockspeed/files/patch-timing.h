--- timing.h.orig	Tue Oct 13 15:37:28 1998
+++ timing.h	Wed Dec 25 17:20:03 2002
@@ -3,6 +3,7 @@
 
 #include "hasrdtsc.h"
 #include "hasgethr.h"
+#include "hasclock_gettime.h"
 #include <sys/types.h>
 #include <sys/time.h>
 
@@ -25,11 +26,20 @@
 #define timing_diff(x,y) ((double) ((x)->t - (y)->t))
 
 #else
+#ifdef HASCLOCK_GETTIME
+
+typedef struct { struct timespec t; } timing;
+#define timing_now(x) ((void) clock_gettime(CLOCK_REALTIME, &((x)->t)))
+/* in seconds */
+#define timing_diff(x,y) (((x)->t.tv_sec - (double) (y)->t.tv_sec) + (4294967296.0*((x)->t.tv_nsec - (double) (y)->t.tv_nsec))/1e9)
+
+#else
 
 #define timing timing_basic
 #define timing_now timing_basic_now
 #define timing_diff timing_basic_diff
 
+#endif
 #endif
 #endif
 
