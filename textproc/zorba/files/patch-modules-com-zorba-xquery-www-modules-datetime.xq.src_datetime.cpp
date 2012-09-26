--- ./modules/com/zorba-xquery/www/modules/datetime.xq.src/datetime.cpp.orig	2012-06-21 11:21:17.000000000 +0200
+++ ./modules/com/zorba-xquery/www/modules/datetime.xq.src/datetime.cpp	2012-06-21 11:03:07.000000000 +0200
@@ -19,7 +19,9 @@
 #include <zorba/singleton_item_sequence.h>
 
 #include <time.h>
+#ifdef WIN21
 #include <sys/timeb.h>
+#endif
 #ifdef UNIX
 #include <sys/time.h>
 #endif
@@ -40,16 +42,21 @@
   lSummerTimeShift = -timebuffer.timezone * 60;
   if (gmtm.tm_isdst != 0)
     lSummerTimeShift += 3600;
-#else
-  struct timeb timebuffer;
-  ftime( &timebuffer );
-  localtime_r(&timebuffer.time, &gmtm); //thread safe localtime on Linux
-  localtime_r(&timebuffer.time, &gmtm); //thread safe localtime on Linux
-  lSummerTimeShift = gmtm.tm_gmtoff;
-#endif
 
   timezone = lSummerTimeShift; // in seconds
   millitm = timebuffer.millitm;
+#else
+  struct timeval tv;
+  struct timezone tz;
+  gettimeofday( &tv, &tz );
+  localtime_r(&tv.tv_sec, &gmtm); //thread safe localtime on Unix
+
+  if (tz.tz_dsttime != 0)
+     lSummerTimeShift = 3600;
+
+  timezone = -tz.tz_minuteswest * 60 + lSummerTimeShift; // in seconds
+  millitm = tv.tv_usec / 1000;
+#endif
 }
 
 /******************************************************************************
