--- hald-runner/runner.c.orig	2010-11-05 19:26:05.673393765 +0200
+++ hald-runner/runner.c	2010-11-05 19:26:33.471393058 +0200
@@ -281,7 +281,7 @@ run_request_run (run_request *r, DBusCon
 	}
 	g_free (program_dir);
 
-	if (r->input) {
+	if (r->input && strlen(r->input) > 0) {
 		if (write(stdin_v, r->input, strlen(r->input)) != (ssize_t) strlen(r->input))
 			printf("Warning: Error while writing r->input (%s) to stdin_v.\n", r->input);
 		close(stdin_v);
