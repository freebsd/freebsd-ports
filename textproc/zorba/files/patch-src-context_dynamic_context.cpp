--- src/context/dynamic_context.cpp.orig	2011-09-10 17:56:15.000000000 +0200
+++ src/context/dynamic_context.cpp	2011-09-15 09:54:19.000000000 +0200
@@ -18,7 +18,9 @@
 #include "common/common.h"
 #include <assert.h>
 #include <time.h>
+#ifdef WIN32
 #include <sys/timeb.h>
+#endif
 #ifdef UNIX
 #include <sys/time.h>
 #endif
@@ -192,10 +194,10 @@
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
 
@@ -207,7 +209,11 @@
                                    gmtm.tm_mday,
                                    gmtm.tm_hour,
                                    gmtm.tm_min,
+#ifdef WIN32
                                    gmtm.tm_sec + timebuffer.millitm/1000.0,
+#else
+                                   gmtm.tm_sec + tv.tv_usec/1000000.0,
+#endif
                                    static_cast<short>(theTimezone/3600));
 
 }
