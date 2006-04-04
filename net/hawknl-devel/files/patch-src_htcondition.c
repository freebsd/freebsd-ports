--- src/htcondition.c	Sun Mar  5 16:05:39 2006
+++ src/htcondition.c	Sun Mar  5 16:06:17 2006
@@ -37,8 +37,6 @@
 
 #else /* !HT_WIN_THREADS */
 
-#include <sys/timeb.h>
-
 #ifdef HL_WINDOWS_APP
 #define timeb _timeb
 #define ftime _ftime
@@ -156,13 +154,14 @@
 #else
         int                 result = 0;
         struct timespec     tv;
-        struct timeb        t;
+        struct timeval       t;
+        struct timezone     tz;
         long                ms;
 
         /* convert timeout to an absolute time */
-        ftime(&t);
-        ms = t.millitm + timeout;
-        tv.tv_sec = t.time + (ms / 1000);
+	gettimeofday(&t, &tz);
+        ms = (t.tv_sec * 1000) + timeout;
+        tv.tv_sec = t.tv_sec + (ms / 1000);
         tv.tv_nsec = (ms % 1000) * 1000000;
 
         (void)pthread_mutex_lock((pthread_mutex_t *)&cv->mutex);
