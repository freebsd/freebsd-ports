--- src/opts.h.orig	Mon Feb 23 01:17:30 2004
+++ src/opts.h	Sun May 23 17:53:00 2004
@@ -17,6 +17,7 @@
 	int filestomonitor;
 	int filechangetimeout;
 	int showaction;
+	char *exec_command;
 };
 struct arguments_t {
 	char **args;
