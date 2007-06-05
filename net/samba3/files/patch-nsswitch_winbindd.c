--- nsswitch/winbindd.c.orig	Sun Apr 22 01:00:32 2007
+++ nsswitch/winbindd.c	Mon Jun  4 02:59:13 2007
@@ -303,6 +303,9 @@
 	if (state->mem_ctx == NULL)
 		return;
 
+	/* Remember who asked us. */
+	state->pid = state->request.pid;
+
 	/* Process command */
 
 	for (table = dispatch_table; table->fn; table++) {
