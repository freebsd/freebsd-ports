--- libatalk/adouble/ad_open.c.orig	2014-05-27 12:33:15.000000000 -0400
+++ libatalk/adouble/ad_open.c	2014-05-27 12:34:00.000000000 -0400
@@ -586,7 +586,7 @@ static int ad_convert_osx(const char *pa
 
     origlen = ad_getentryoff(ad, ADEID_RFORK) + ad_getentrylen(ad, ADEID_RFORK);
 
-    map = mmap(NULL, origlen, PROT_WRITE, MAP_SHARED, ad_reso_fileno(ad), 0);
+    map = mmap(NULL, origlen, PROT_READ | PROT_WRITE, MAP_SHARED, ad_reso_fileno(ad), 0);
     if (map == MAP_FAILED) {
         LOG(log_error, logtype_ad, "mmap AppleDouble: %s\n", strerror(errno));
         EC_FAIL;
