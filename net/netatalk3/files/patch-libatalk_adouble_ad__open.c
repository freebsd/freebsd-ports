--- libatalk/adouble/ad_open.c.orig	2024-01-02 07:44:09 UTC
+++ libatalk/adouble/ad_open.c
@@ -668,6 +668,11 @@ reread:
     int                 retry_read = 0;
 
 reread:
+    if (hst == NULL) {
+        hst = &st;
+        EC_NEG1( fstat(ad_reso_fileno(ad), hst) );
+    }
+
     LOG(log_debug, logtype_ad, "ad_header_read_osx: %s", path ? fullpathname(path) : "");
     ad_init_old(&adosx, AD_VERSION_EA, ad->ad_options);
     buf = &adosx.ad_data[0];
@@ -707,7 +712,7 @@ reread:
         return -1;
     }
 
-    if (parse_entries(&adosx, nentries, header_len) != 0) {
+    if (parse_entries(&adosx, nentries, hst->st_size) != 0) {
         LOG(log_warning, logtype_ad, "ad_header_read(%s): malformed AppleDouble",
             path ? fullpathname(path) : "");
             errno = EIO;
@@ -725,6 +730,7 @@ reread:
         }
         retry_read++;
         if (ad_convert_osx(path, &adosx) == 1) {
+	    hst = NULL;
             goto reread;
         }
         errno = EIO;
@@ -738,11 +744,6 @@ reread:
         LOG(log_error, logtype_ad, "ad_header_read_osx: problem with rfork entry offset.");
         errno = EIO;
         return -1;
-    }
-
-    if (hst == NULL) {
-        hst = &st;
-        EC_NEG1( fstat(ad_reso_fileno(ad), &st) );
     }
 
     ad_setentryoff(ad, ADEID_RFORK, ad_getentryoff(&adosx, ADEID_RFORK));
