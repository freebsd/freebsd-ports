--- mod_geoip.c.orig	Mon May 19 15:03:19 2003
+++ mod_geoip.c	Mon May 19 15:08:36 2003
@@ -209,7 +209,8 @@
   }
 
   databaseType = GeoIP_database_edition(cfg->gip);
-  if (databaseType == GEOIP_COUNTRY_EDITION) {
+  switch (databaseType) {
+  case GEOIP_COUNTRY_EDITION:
     country_id = GeoIP_country_id_by_addr(cfg->gip, ipaddr);
 
     if (country_id > 0) {
@@ -224,7 +225,8 @@
         ap_table_set(r->subprocess_env, "GEOIP_COUNTRY_NAME", country_name);
       }
     }
-  } else if (databaseType == GEOIP_REGION_EDITION) {
+    break;
+  case GEOIP_REGION_EDITION:
     giregion = GeoIP_region_by_name (cfg->gip, ipaddr);
     if (giregion != NULL) {
       if (cfg->GeoIPOutput & GEOIP_NOTES) {
@@ -241,7 +243,9 @@
       }
       GeoIPRegion_delete(giregion);
     }
-  } else if (databaseType == GEOIP_CITY_EDITION) {
+    break;
+  case GEOIP_CITY_EDITION_REV0:
+  case GEOIP_CITY_EDITION_REV1:
     gir = GeoIP_record_by_addr(cfg->gip, ipaddr);
     if (gir != NULL) {
       if (cfg->GeoIPOutput & GEOIP_NOTES) {
@@ -261,6 +265,7 @@
           ap_table_set(r->subprocess_env, "GEOIP_CITY", gir->city);
       }
     }
+    break;
   }
   return OK;
 }
