--- src/context/dynamic_context.cpp.orig	2011-08-11 15:02:06.000000000 +0200
+++ src/context/dynamic_context.cpp	2011-08-11 15:10:43.000000000 +0200
@@ -16,7 +16,9 @@
 #include "common/common.h"
 #include <assert.h>
 #include <time.h>
+#if defined(WIN32)
 #include <sys/timeb.h>
+#endif
 #ifdef UNIX
 #include <sys/time.h>
 #endif
@@ -147,10 +149,10 @@
     if (gmtm.tm_isdst != 0)
       lTimeShift = -timebuffer.timezone*60 + 3600;
 #else
-    struct timeb timebuffer;
-    ftime( &timebuffer );
+    struct timeval tv;
+    gettimeofday( &tv, 0 );
     struct ::tm gmtm;
-    localtime_r(&timebuffer.time, &gmtm); //thread safe localtime on Linux
+    localtime_r(&tv.tv_sec, &gmtm); //thread safe localtime on Linux
     lTimeShift = gmtm.tm_gmtoff;
 #endif
 
@@ -162,7 +164,11 @@
                                      gmtm.tm_mday,
                                      gmtm.tm_hour,
                                      gmtm.tm_min,
+#if defined(WIN32)
                                      gmtm.tm_sec + timebuffer.millitm/1000.0,
+#else
+                                     gmtm.tm_sec + tv.tv_usec/1000000.0,
+#endif
                                      theTimezone/3600);
 
 #if WIN32
@@ -170,8 +176,6 @@
     time(&t0);
     GENV_ITEMFACTORY->createLong(current_time_millis, t0*1000);
 #else
-    timeval tv;
-    gettimeofday(&tv, 0);
     long long millis = tv.tv_sec;
     millis = millis * 1000 + tv.tv_usec/1000;
     GENV_ITEMFACTORY->createLong(current_time_millis, millis);
