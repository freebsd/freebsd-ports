--- options.c.orig	Thu Mar  8 03:31:32 2001
+++ options.c	Thu Mar  8 03:31:32 2001
@@ -141 +141 @@
-  rprintf(F," -e, --rsh=COMMAND           specify rsh replacement\n");
+  rprintf(F," -e, --rsh=COMMAND           specify rsh replacement (default %s)\n", RSYNC_SSH);
