--- src/rinetd.c.orig	2023-10-07 16:13:36 UTC
+++ src/rinetd.c
@@ -927,7 +927,7 @@ RETSIGTYPE quit(int s)
 
 void registerPID(char const *pid_file_name)
 {
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 	FILE *pid_file = fopen(pid_file_name, "w");
 	if (pid_file == NULL) {
 		/* non-fatal, non-Linux may lack /var/run... */
