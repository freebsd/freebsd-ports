--- doc/udisks2-docs.xml.daemon.sed.orig	2019-10-03 03:15:30 UTC
+++ doc/udisks2-docs.xml.daemon.sed
@@ -0,0 +1,7 @@
+/<!-- DAEMON_MAN_PAGE -->/ {
+    r udisks2-docs.xml.daemon.man
+    d }
+
+/<!-- DAEMON_PART -->/ {
+    r udisks2-docs.xml.daemon.part
+    d }
