
$FreeBSD$

--- libnautilus-extensions/nautilus-medusa-support.c	2001/05/10 11:39:29	1.1
+++ libnautilus-extensions/nautilus-medusa-support.c	2001/05/10 11:40:00
@@ -108,7 +108,7 @@
 		/* Process files have numbers */
 		if (nautilus_str_to_int (file->d_name,
 					 &process_number)) {
-			stat_file_name = g_strdup_printf ("/proc/%d/stat", process_number);
+			stat_file_name = g_strdup_printf ("/proc/%d/status", process_number);
 			stat_file = fopen (stat_file_name, "r");
 			g_free (stat_file_name);
 
