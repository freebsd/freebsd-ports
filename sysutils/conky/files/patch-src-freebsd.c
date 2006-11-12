--- src/freebsd.c.orig	Sun Nov 12 09:23:59 2006
+++ src/freebsd.c	Sun Nov 12 09:24:20 2006
@@ -290,7 +290,7 @@
 	size_t len = sizeof (cp_time);
 
 	/* add check for !info.cpu_usage since that mem is freed on a SIGUSR1 */
-	if ((cpu_setup == 0)) || (!info.cpu_usage) {
+	if ((cpu_setup == 0) || (!info.cpu_usage)) {
 		get_cpu_count();
 		cpu_setup = 1;
 	}
