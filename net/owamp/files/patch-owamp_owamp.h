--- owamp/owamp.h.orig	2012-03-27 02:23:05 UTC
+++ owamp/owamp.h
@@ -1635,14 +1635,13 @@ OWPTestDiskspace(
 #define timespecisset(tvp)      ((tvp)->tv_sec || (tvp)->tv_nsec)
 #endif
 
-#ifndef timespeccmp
+#undef	timespeccmp
 #define timespeccmp(tvp, uvp, cmp)          \
     (((tvp)->tv_sec == (uvp)->tv_sec) ?     \
      ((tvp)->tv_nsec cmp (uvp)->tv_nsec) :  \
      ((tvp)->tv_sec cmp (uvp)->tv_sec))
-#endif
 
-#ifndef        timespecadd
+#undef	timespecadd
 #define timespecadd(vvp, uvp)               \
     do {                                    \
         (vvp)->tv_sec += (uvp)->tv_sec;     \
@@ -1652,9 +1651,8 @@ OWPTestDiskspace(
             (vvp)->tv_nsec -= 1000000000;   \
         }                                   \
     } while (0)
-#endif
 
-#ifndef timespecsub
+#undef	timespecsub
 #define timespecsub(vvp, uvp)               \
     do {                                    \
         (vvp)->tv_sec -= (uvp)->tv_sec;     \
@@ -1664,9 +1662,8 @@ OWPTestDiskspace(
             (vvp)->tv_nsec += 1000000000;   \
         }                                   \
     } while (0)
-#endif
 
-#ifndef        timespecdiff
+#undef		timespecdiff
 #define        timespecdiff(vvp,uvp)        \
     do {                                    \
         struct timespec        ts1_,ts2_;   \
@@ -1680,7 +1677,6 @@ OWPTestDiskspace(
         timespecsub(&ts1_,&ts2_);           \
         *vvp = ts1_;                        \
     } while(0)
-#endif
 
 extern OWPNum64
 OWPGetRTTBound(
