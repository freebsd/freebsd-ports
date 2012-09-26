--- src/context/dynamic_context.cpp.orig	2012-06-13 06:56:48.000000000 +0200
+++ src/context/dynamic_context.cpp	2012-06-21 09:49:08.000000000 +0200
@@ -18,7 +18,9 @@
 #include "common/common.h"
 #include <assert.h>
 #include <time.h>
+#ifdef WIN32
 #include <sys/timeb.h>
+#endif
 #ifdef UNIX
 #include <sys/time.h>
 #include <unistd.h>
@@ -238,10 +240,10 @@
   if (gmtm.tm_isdst != 0)
     lTimeShift += 3600;
 #else
-  struct timeb timebuffer;
-  ftime( &timebuffer );
+  struct timeval tv;
+  gettimeofday( &tv, 0 );
   struct ::tm gmtm;
-  localtime_r(&timebuffer.time, &gmtm); //thread safe localtime on Linux
+  localtime_r(&tv.tv_sec, &gmtm); //thread safe localtime on Linux
   lTimeShift = gmtm.tm_gmtoff;
 #endif
 
@@ -253,7 +255,11 @@
                                    static_cast<short>(gmtm.tm_mday),
                                    static_cast<short>(gmtm.tm_hour),
                                    static_cast<short>(gmtm.tm_min),
+#ifdef WIN32
                                    gmtm.tm_sec + timebuffer.millitm/1000.0,
+#else
+                                   gmtm.tm_sec + tv.tv_usec/1000000.0,
+#endif
                                    static_cast<short>(theTimezone/3600));
 
 }
