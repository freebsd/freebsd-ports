--- mod_geoip.c	2008/09/16 10:31:43	1.39
+++ mod_geoip.c	2009/02/06 00:33:10	1.40
@@ -317,8 +317,7 @@
 
     if ( !cfg )
       continue;
-    if ( !cfg->GeoIPEnable )
-      continue;
+    
     if (cfg->gips)
       continue;
 
