The code is using gnu C extensions. The following new patchfile under files/ fixes the issue:

# cat files/patch-descriptors.c
--- descriptors.c.orig	2016-06-20 13:13:56 UTC
+++ descriptors.c
@@ -1000,6 +1000,16 @@ void parse_T2_delivery_system_descriptor
               }
 }
 
+__u8 LeapYear(__u16 year) {
+     if ((year % 400) == 0)
+       return 1;
+     else if ((year % 100) == 0)
+       return 0;
+     else if ((year % 4) == 0)
+       return 1;
+     return 0;
+}
+
 
 /* 300468 v011101 annex C, Conversion between time and date conventions
  * NOTE: These formulas are applicable between the inclusive dates 1900 March 1 to 2100 February 28.
@@ -1011,16 +1021,6 @@ struct tm modified_julian_date_to_utc(__
         int _M = (int) (MJD - 14956.1 - (int) (_Y * 365.25)) / 30.6001;
         int K = (_M == 14) ? 1 : (_M == 15) ? 1 : 0;
 
-        __u8 LeapYear(__u16 year) {
-             if ((year % 400) == 0)
-                return 1;
-             else if ((year % 100) == 0)
-                return 0;
-             else if ((year % 4) == 0)
-                return 1;
-             return 0;
-        }
-        
         memset(&utc, 0, sizeof(struct tm));
         utc.tm_mday = MJD - 14956 - (int) (_Y * 365.25) - (int) (_M * 30.6001);
         utc.tm_year = _Y + K;
