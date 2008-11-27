--- scripts/restricted_from_passwd.py.orig	2008-11-26 12:06:31.231726279 -0500
+++ scripts/restricted_from_passwd.py	2008-11-26 12:06:36.696728675 -0500
@@ -11,7 +11,7 @@
 #
 ############################################################################
 
-RESTRICTED_SHELLS = ("/sbin/nologin",
+RESTRICTED_SHELLS = ("/usr/sbin/nologin",
                      "/sbin/shutdown",
                      "/sbin/halt")
 
