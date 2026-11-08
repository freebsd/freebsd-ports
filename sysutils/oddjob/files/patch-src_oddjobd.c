--- src/oddjobd.c.orig	2026-08-10 15:02:29 UTC
+++ src/oddjobd.c
@@ -34,6 +34,7 @@
 #include <sys/socket.h>
 #include <sys/stat.h>
 #include <sys/wait.h>
+#include <signal.h>
 #include <errno.h>
 #include <fcntl.h>
 #include <fnmatch.h>
@@ -2985,7 +2986,12 @@ main(int argc, char **argv)
 
 	/* Open a connection to the message bus. */
 	check_selinux_applicable();
-	ctx = oddjob_dbus_listeners_new(options.bus, globals.selinux_enabled);
+	ctx = oddjob_dbus_listeners_new(options.bus,
+#ifdef SELINUX_ACLS
+				       globals.selinux_enabled);
+#else
+				       FALSE);
+#endif
 	if (ctx == NULL) {
 		fprintf(stderr, "Error connecting to D-Bus!\n");
 		return 2;
