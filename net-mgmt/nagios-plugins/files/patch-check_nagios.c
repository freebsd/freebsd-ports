--- plugins/check_nagios.c.orig	Thu Mar 11 16:17:08 2004
+++ plugins/check_nagios.c	Fri Dec  3 22:28:53 2004
@@ -132,7 +132,7 @@
                         }
 
 			/* May get empty procargs */
-			if (!strstr(procargs, argv[0]) && strstr(procprog, process_string) && strcmp(procargs,"")) {
+			if (!strstr(procargs, argv[0]) && strcmp(procargs,"") && strstr(procargs, process_string)) {
 				proc_entries++;
 				if (verbose >= 2) {
 					printf (_("Found process: %s %s\n"), procprog, procargs);
