--- lib/probes/EchoPingIcp.pm.orig	Sun Jan 11 18:06:12 2004
+++ lib/probes/EchoPingIcp.pm	Sun Jan 11 18:06:12 2004
@@ -14,7 +14,7 @@
  *** Probes ***
  + EchoPingIcp
 
- binary = /usr/bin/echoping # mandatory
+ binary = %%PREFIX%%/bin/echoping # mandatory
  
  *** Targets ***
 
