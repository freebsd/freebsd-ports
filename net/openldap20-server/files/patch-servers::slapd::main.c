--- servers/slapd/main.c.orig	Fri Jan  4 21:38:28 2002
+++ servers/slapd/main.c	Fri Aug 22 14:25:23 2003
@@ -480,6 +480,13 @@
 #endif
 	slapd_daemon_destroy();

+	if ( slapd_pid_file != NULL ) {
+		unlink( slapd_pid_file );
+	}
+	if ( slapd_args_file != NULL ) {
+		unlink( slapd_args_file );
+	}
+
 #ifdef CSRIMALLOC
 	mal_dumpleaktrace( leakfile );
 #endif
