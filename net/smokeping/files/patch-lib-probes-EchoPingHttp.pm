--- lib/probes/EchoPingHttp.pm.orig	Sun Jan 11 18:06:12 2004
+++ lib/probes/EchoPingHttp.pm	Sun Jan 11 18:06:12 2004
@@ -13,7 +13,7 @@
  *** Probes ***
  + EchoPingHttp
 
- binary = /usr/bin/echoping # mandatory
+ binary = %%PREFIX%%/bin/echoping # mandatory
  
 
  *** Targets ***
