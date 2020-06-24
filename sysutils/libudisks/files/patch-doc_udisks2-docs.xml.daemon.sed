--- doc/udisks2-docs.xml.daemon.sed.orig	2020-05-26 15:07:07 UTC
+++ doc/udisks2-docs.xml.daemon.sed
@@ -5,3 +5,10 @@
 /<!-- DAEMON_PART -->/ {
     r udisks2-docs.xml.daemon.part
     d }
+/<!-- DAEMON_MAN_PAGE -->/ {
+    r udisks2-docs.xml.daemon.man
+    d }
+
+/<!-- DAEMON_PART -->/ {
+    r udisks2-docs.xml.daemon.part
+    d }
