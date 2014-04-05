--- ./scripts/restricted_from_passwd.py.orig	2013-12-28 18:51:41.000000000 +0100
+++ ./scripts/restricted_from_passwd.py	2013-12-28 18:51:41.000000000 +0100
@@ -12,6 +12,7 @@
 ############################################################################
 
 RESTRICTED_SHELLS = ("/sbin/nologin",
+                     "/usr/sbin/nologin",
                      "/sbin/shutdown",
                      "/sbin/halt")
 
