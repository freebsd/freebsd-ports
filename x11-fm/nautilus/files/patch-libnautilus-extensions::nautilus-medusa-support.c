
$FreeBSD$

--- libnautilus-private/nautilus-medusa-support.c.orig	Wed Apr 11 21:36:16 2001
+++ libnautilus-private/nautilus-medusa-support.c	Mon May 14 17:45:24 2001
@@ -84,7 +84,7 @@
 		 */
 		status = NAUTILUS_CRON_STATUS_OFF;
 
-		stat_file_name = g_strdup_printf ("/proc/%d/stat", process_number);
+		stat_file_name = g_strdup_printf ("/proc/%d/status", process_number);
 		stat_file = fopen (stat_file_name, "r");
 		g_free (stat_file_name);
 		
