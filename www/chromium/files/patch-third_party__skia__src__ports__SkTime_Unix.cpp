--- third_party/skia/src/ports/SkTime_Unix.cpp.orig	2015-07-22 19:35:29.020385000 -0400
+++ third_party/skia/src/ports/SkTime_Unix.cpp	2015-07-22 19:49:28.094432000 -0400
@@ -24,7 +24,11 @@
         int offset = tstruct->tm_isdst == 1 ? 60 : 0;
 
         // http://pubs.opengroup.org/onlinepubs/009695399/basedefs/time.h.html
+#if defined(__FreeBSD__)
+        dt->fTimeZoneMinutes = SkToS16(offset - tstruct->tm_gmtoff / 60);
+#else
         dt->fTimeZoneMinutes = SkToS16(offset - timezone / 60);
+#endif
         dt->fYear       = tstruct->tm_year + 1900;
         dt->fMonth      = SkToU8(tstruct->tm_mon + 1);
         dt->fDayOfWeek  = SkToU8(tstruct->tm_wday);
