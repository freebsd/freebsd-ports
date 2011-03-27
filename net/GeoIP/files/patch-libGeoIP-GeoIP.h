--- libGeoIP/GeoIP.h.orig	2009-02-24 19:03:23.000000000 +0300
+++ libGeoIP/GeoIP.h	2010-11-24 19:21:26.000000000 +0300
@@ -241,10 +241,6 @@
 /* Get timezone from country and region code */
 GEOIP_API const char * GeoIP_time_zone_by_country_and_region(const char *country_code, const char *region_code);
 
-#ifdef BSD
-#define memcpy(dest, src, n) bcopy(src, dest, n)
-#endif
-
 #ifdef __cplusplus
 }
 #endif
