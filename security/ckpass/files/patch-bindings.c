--- bindings.c.orig	2011-09-12 12:31:15.000000000 +0300
+++ bindings.c	2011-09-12 12:45:59.000000000 +0300
@@ -57,7 +57,8 @@
 	(b+1)->key = 0; /* Make last one be the terminating binding. */
 
 	/* Keep bindings sorted by command. */
-	for(b--; b >= *set && strcmp(command, b->command) < 0; b--) {
+	const char *bcommand=&b->command;
+	for(b--; b >= *set && strcmp(command, bcommand) < 0; b--) {
 		(b+1)->key = b->key;
 		(b+1)->command = b->command;
 	}
