--- lib/probes/LDAP.pm.orig	Fri Feb 20 00:28:14 2004
+++ lib/probes/LDAP.pm	Fri Feb 20 00:28:44 2004
@@ -13,7 +13,7 @@
  *** Probes ***
  + LDAP
 
- passwordfile = /usr/share/smokeping/etc/password # optional
+ passwordfile = %%PREFIX%%/etc/smokeping/password # optional
  sleeptime = 0.5 # optional, 1 second by default
 
  *** Targets ***
