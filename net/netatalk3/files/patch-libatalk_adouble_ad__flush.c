--- libatalk/adouble/ad_flush.c.orig	2022-03-22 04:50:23 UTC
+++ libatalk/adouble/ad_flush.c
@@ -151,6 +151,7 @@ int ad_rebuild_adouble_header_osx(struct adouble *ad, 
     uint32_t       temp;
     uint16_t       nent;
     char           *buf;
+    char           *ade = NULL;
 
     LOG(log_debug, logtype_ad, "ad_rebuild_adouble_header_osx");
 
@@ -184,8 +185,11 @@ int ad_rebuild_adouble_header_osx(struct adouble *ad, 
     memcpy(buf, &temp, sizeof( temp ));
     buf += sizeof( temp );
 
-    memcpy(adbuf + ADEDOFF_FINDERI_OSX, ad_entry(ad, ADEID_FINDERI), ADEDLEN_FINDERI);
+    ade = ad_entry(ad, ADEID_FINDERI);
+    AFP_ASSERT(ade != NULL);
 
+    memcpy(adbuf + ADEDOFF_FINDERI_OSX, ade, ADEDLEN_FINDERI);
+
     /* rfork */
     temp = htonl( EID_DISK(ADEID_RFORK) );
     memcpy(buf, &temp, sizeof( temp ));
@@ -211,8 +215,12 @@ int ad_copy_header(struct adouble *add, struct adouble
 {
     uint32_t       eid;
     uint32_t       len;
+    char *src = NULL;
+    char *dst = NULL;
 
     for ( eid = 0; eid < ADEID_MAX; eid++ ) {
+        src = dst = NULL;
+
         if ( ads->ad_eid[ eid ].ade_off == 0 || add->ad_eid[ eid ].ade_off == 0 )
             continue;
 
@@ -226,17 +234,28 @@ int ad_copy_header(struct adouble *add, struct adouble
             continue;
         default:
             ad_setentrylen( add, eid, len );
-            memcpy( ad_entry( add, eid ), ad_entry( ads, eid ), len );
+            dst = ad_entry(add, eid);
+            AFP_ASSERT(dst != NULL);
+
+            src = ad_entry(ads, eid);
+            AFP_ASSERT(src != NULL);
+
+            memcpy( dst, src, len );
         }
     }
     add->ad_rlen = ads->ad_rlen;
 
     if (((ads->ad_vers == AD_VERSION2) && (add->ad_vers == AD_VERSION_EA))
         || ((ads->ad_vers == AD_VERSION_EA) && (add->ad_vers == AD_VERSION2))) {
+        src = dst = NULL;
         cnid_t id;
-        memcpy(&id, ad_entry(add, ADEID_PRIVID), sizeof(cnid_t));
+
+        dst = ad_entry(add, ADEID_PRIVID);
+        AFP_ASSERT(dst != NULL);
+
+        memcpy(&id, dst, sizeof(cnid_t));
         id = htonl(id);
-        memcpy(ad_entry(add, ADEID_PRIVID), &id, sizeof(cnid_t));
+        memcpy(dst, &id, sizeof(cnid_t));
     }
     return 0;
 }
