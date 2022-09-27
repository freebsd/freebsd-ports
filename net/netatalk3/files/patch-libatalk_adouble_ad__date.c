--- libatalk/adouble/ad_date.c.orig	2022-02-28 13:32:06 UTC
+++ libatalk/adouble/ad_date.c
@@ -10,6 +10,7 @@ int ad_setdate(struct adouble *ad,
                unsigned int dateoff, uint32_t date)
 {
     int xlate = (dateoff & AD_DATE_UNIX);
+    char *ade = NULL;
 
     dateoff &= AD_DATE_MASK;
     if (xlate)
@@ -20,8 +21,13 @@ int ad_setdate(struct adouble *ad,
 
     if (dateoff > AD_DATE_ACCESS)
         return -1;
-    memcpy(ad_entry(ad, ADEID_FILEDATESI) + dateoff, &date, sizeof(date));
 
+    ade = ad_entry(ad, ADEID_FILEDATESI);
+    if (ade == NULL) {
+        return -1;
+    }
+    memcpy(ade + dateoff, &date, sizeof(date));
+
     return 0;
 }
 
@@ -29,6 +35,7 @@ int ad_getdate(const struct adouble *ad,
                unsigned int dateoff, uint32_t *date)
 {
     int xlate = (dateoff & AD_DATE_UNIX);
+    char *ade = NULL;
 
     dateoff &= AD_DATE_MASK;
     if (!ad_getentryoff(ad, ADEID_FILEDATESI))
@@ -36,7 +43,13 @@ int ad_getdate(const struct adouble *ad,
 
     if (dateoff > AD_DATE_ACCESS)
         return -1;
-    memcpy(date, ad_entry(ad, ADEID_FILEDATESI) + dateoff, sizeof(uint32_t));
+
+
+    ade = ad_entry(ad, ADEID_FILEDATESI);
+    if (ade == NULL) {
+        return -1;
+    }
+    memcpy(date, ade + dateoff, sizeof(uint32_t));
 
     if (xlate)
         *date = AD_DATE_TO_UNIX(*date);
