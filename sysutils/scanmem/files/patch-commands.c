--- commands.c.orig	2010-01-19 07:37:07 UTC
+++ commands.c
@@ -104,7 +104,7 @@ bool execcommand(globals_t * vars, const
 
     np = commands->head;
 
-    str = tok = strdupa(commandline);
+    str = tok = strdup(commandline);
 
     /* tokenize command line into an argument vector */
     for (argc = 0; tok; argc++, str = NULL) {
