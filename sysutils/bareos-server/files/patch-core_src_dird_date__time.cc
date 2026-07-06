--- core/src/dird/date_time.cc.orig	2026-06-24 10:04:53 UTC
+++ core/src/dird/date_time.cc
@@ -76,7 +76,8 @@ void DateTime::PrintDebugMessage(int debug_level) cons
 
 void DateTime::PrintDebugMessage(int debug_level) const
 {
-  Dmsg8(debug_level, "now = %lx: h=%d m=%d md=%d wd=%d woy=%d yday=%d\n ", time,
+  Dmsg8(debug_level, "now = %llx: h=%d m=%d md=%d wd=%d woy=%d yday=%d\n ",
+        (long long)time,
         hour, month, day_of_month, day_of_week, week_of_year, day_of_year);
 }
 
