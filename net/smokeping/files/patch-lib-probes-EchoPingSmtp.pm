--- lib/probes/EchoPingSmtp.pm.orig	Sun Jan 11 18:06:12 2004
+++ lib/probes/EchoPingSmtp.pm	Sun Jan 11 18:06:12 2004
@@ -13,7 +13,7 @@
  *** Probes ***
  + EchoPingSmtp
 
- binary = /usr/bin/echoping # mandatory
+ binary = %%PREFIX%%/bin/echoping # mandatory
 
  *** Targets ***
  probe = EchoPingSmtp
