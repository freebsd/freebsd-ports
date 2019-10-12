--- doc/udisks2-sections.txt.daemon.sed.orig	2019-10-03 03:15:30 UTC
+++ doc/udisks2-sections.txt.daemon.sed
@@ -0,0 +1,3 @@
+/<!-- DAEMON_GENERATED_SECTIONS -->/ {
+    r udisks2-sections.txt.daemon.sections
+    d }
