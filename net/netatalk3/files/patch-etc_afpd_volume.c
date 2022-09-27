--- etc/afpd/volume.c.orig	2022-03-22 04:50:23 UTC
+++ etc/afpd/volume.c
@@ -305,6 +305,7 @@ static int getvolparams(const AFPObj *obj, uint16_t bi
     VolSpace            xbfree, xbtotal; /* extended bytes */
     char        *data, *nameoff = NULL;
     char                *slash;
+    char        *ade = NULL;
 
     LOG(log_debug, logtype_afpd, "getvolparams: Volume '%s'", vol->v_localname);
 
@@ -328,8 +329,10 @@ static int getvolparams(const AFPObj *obj, uint16_t bi
             slash = vol->v_path;
         if (ad_getentryoff(&ad, ADEID_NAME)) {
             ad_setentrylen( &ad, ADEID_NAME, strlen( slash ));
-            memcpy(ad_entry( &ad, ADEID_NAME ), slash,
-                   ad_getentrylen( &ad, ADEID_NAME ));
+            ade = ad_entry(&ad, ADEID_NAME);
+            AFP_ASSERT(ade != NULL);
+
+            memcpy(ade, slash, ad_getentrylen( &ad, ADEID_NAME ));
         }
         vol_setdate(vol->v_vid, &ad, st->st_mtime);
         ad_flush(&ad);
