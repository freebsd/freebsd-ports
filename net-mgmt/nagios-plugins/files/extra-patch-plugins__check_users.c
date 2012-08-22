--- plugins/check_users.c.orig	2012-06-28 03:02:47.000000000 +0930
+++ plugins/check_users.c	2012-08-05 10:29:00.000000000 +0930
@@ -35,8 +35,8 @@
 const char *email = "nagiosplug-devel@lists.sourceforge.net";
 
 #include "common.h"
+#include "popen.h"
 #include "utils.h"
-#include <utmpx.h>
 
 #define possibly_set(a,b) ((a) == 0 ? (b) : 0)
 
@@ -52,8 +52,8 @@
 {
 	int users = -1;
 	int result = STATE_UNKNOWN;
+	char input_buffer[MAX_INPUT_BUFFER];
 	char *perf;
-	struct utmpx *putmpx;
 
 	setlocale (LC_ALL, "");
 	bindtextdomain (PACKAGE, LOCALEDIR);
@@ -67,18 +67,43 @@
 	if (process_arguments (argc, argv) == ERROR)
 		usage4 (_("Could not parse arguments"));
 
+	/* run the command */
+	child_process = spopen (WHO_COMMAND);
+	if (child_process == NULL) {
+		printf (_("Could not open pipe: %s\n"), WHO_COMMAND);
+		return STATE_UNKNOWN;
+	}
+
+	child_stderr = fdopen (child_stderr_array[fileno (child_process)], "r");
+	if (child_stderr == NULL)
+		printf (_("Could not open stderr for %s\n"), WHO_COMMAND);
+
 	users = 0;
 
-	/* get currently logged users from utmpx */
-	setutxent ();
+	while (fgets (input_buffer, MAX_INPUT_BUFFER - 1, child_process)) {
 
-	while ((putmpx = getutxent ()) != NULL)
-		if (putmpx->ut_type == USER_PROCESS)
+		/* increment 'users' on all lines except total user count */
+		if (input_buffer[0] != '#') {
 			users++;
+			continue;
+		}
+
+		/* get total logged in users */
+		if (sscanf (input_buffer, _("# users=%d"), &users) == 1)
+			break;
+
+	}
 
-	endutxent ();
+	/* check STDERR */
+	if (fgets (input_buffer, MAX_INPUT_BUFFER - 1, child_stderr))
+		result = possibly_set (result, STATE_UNKNOWN);
+	(void) fclose (child_stderr);
+
+	/* close the pipe */
+	if (spclose (child_process))
+		result = possibly_set (result, STATE_UNKNOWN);
 
-	/* check the user count against warning and critical thresholds */
+	/* else check the user count against warning and critical thresholds */
 	if (users > cusers)
 		result = STATE_CRITICAL;
 	else if (users > wusers)
--- plugins/Makefile.am.orig	2012-06-28 03:02:47.000000000 +0930
+++ plugins/Makefile.am	2012-08-05 10:29:00.000000000 +0930
@@ -101,7 +101,7 @@
 check_time_LDADD = $(NETLIBS)
 check_ntp_time_LDADD = $(NETLIBS) $(MATHLIBS)
 check_ups_LDADD = $(NETLIBS)
-check_users_LDADD = $(BASEOBJS)
+check_users_LDADD = $(BASEOBJS) popen.o
 check_by_ssh_LDADD = $(NETLIBS)
 check_ide_smart_LDADD = $(BASEOBJS)
 negate_LDADD = $(BASEOBJS)
