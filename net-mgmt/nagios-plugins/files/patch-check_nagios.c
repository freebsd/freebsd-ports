--- plugins/check_nagios.c.orig	Sun Jun 19 09:51:52 2005
+++ plugins/check_nagios.c	Sun Jun 19 09:53:28 2005
@@ -26,6 +26,8 @@
 #include "common.h"
 #include "popen.h"
 #include "utils.h"
+#include <sys/types.h>
+#include <sys/stat.h>
 
 int process_arguments (int, char **);
 void print_help (void);
@@ -42,12 +44,12 @@
 {
 	int result = STATE_UNKNOWN;
 	char input_buffer[MAX_INPUT_BUFFER];
-	unsigned long latest_entry_time = 0L;
-	unsigned long temp_entry_time = 0L;
+	unsigned long latest_entry_time;
 	int proc_entries = 0;
 	time_t current_time;
 	char *temp_ptr;
-	FILE *fp;
+	struct stat sb;
+	int err;
 	int procuid = 0;
 	int procppid = 0;
 	int procvsz = 0;
@@ -78,21 +80,14 @@
 	alarm (timeout_interval);
 
 	/* open the status log */
-	fp = fopen (status_log, "r");
-	if (fp == NULL) {
-		printf (_("CRITICAL - Cannot open status log for reading!\n"));
+	err = stat(status_log, &sb);
+	if (err) {
+		printf (_("CRITICAL - Cannot get modification time of status log!\n"));
 		return STATE_CRITICAL;
 	}
 
 	/* get the date/time of the last item updated in the log */
-	while (fgets (input_buffer, MAX_INPUT_BUFFER - 1, fp)) {
-		temp_ptr = strtok (input_buffer, "]");
-		temp_entry_time =
-			(temp_ptr == NULL) ? 0L : strtoul (temp_ptr + 1, NULL, 10);
-		if (temp_entry_time > latest_entry_time)
-			latest_entry_time = temp_entry_time;
-	}
-	fclose (fp);
+	latest_entry_time = sb.st_mtime;
 
 	if (verbose >= 2)
 		printf(_("command: %s\n"), PS_COMMAND);
