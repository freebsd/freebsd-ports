--- lib/probes/Radius.pm.orig	Fri Feb 20 00:29:00 2004
+++ lib/probes/Radius.pm	Fri Feb 20 00:29:21 2004
@@ -13,7 +13,7 @@
  *** Probes ***
  + Radius
 
- passwordfile = /usr/share/smokeping/etc/password
+ passwordfile = %%PREFIX%%/etc/smokeping/password
  secretfile = /etc/raddb/secret
  sleeptime = 0.5 # optional, 1 second by default
 
