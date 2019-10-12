--- doc/udisks2.types.daemon.sed.orig	2019-10-03 03:15:30 UTC
+++ doc/udisks2.types.daemon.sed
@@ -0,0 +1,3 @@
+/\# DAEMON_TYPES/ {
+    r udisks2.types.daemon
+    d }
