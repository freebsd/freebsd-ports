--- lib/probes/passwordchecker.pm.orig	Fri Feb 20 00:29:34 2004
+++ lib/probes/passwordchecker.pm	Fri Feb 20 00:29:55 2004
@@ -16,7 +16,7 @@
  *** Probes ***
  + MyPasswordChecker
  # location of the file containing usernames and passwords
- passwordfile = /usr/share/smokeping/etc/passwords
+ passwordfile = %%PREFIX%%/etc/smokeping/passwords
 
 The specified password file:
 
