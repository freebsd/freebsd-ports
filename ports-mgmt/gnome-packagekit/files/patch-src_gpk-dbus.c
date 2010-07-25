--- src/gpk-dbus.c.orig	2010-07-20 09:56:17.000000000 +0200
+++ src/gpk-dbus.c	2010-07-21 17:14:31.000000000 +0200
@@ -32,6 +32,12 @@
 #include <unistd.h>
 #endif /* HAVE_UNISTD_H */
 
+#ifdef __FreeBSD__
+#include <sys/sysctl.h>
+//#include <errno.h>
+#include <string.h>
+#endif
+
 #include <sys/wait.h>
 #include <fcntl.h>
 
@@ -212,6 +218,13 @@ gpk_dbus_get_exec_for_sender (GpkDbus *d
 	GError *error = NULL;
 	guint pid;
 
+#ifdef __FreeBSD__
+	size_t len;
+	int mib[4];
+/* figure out how to use the above GError */
+	int error2;
+#endif
+
 	g_return_val_if_fail (PK_IS_DBUS (dbus), NULL);
 	g_return_val_if_fail (sender != NULL, NULL);
 
@@ -223,7 +236,29 @@ gpk_dbus_get_exec_for_sender (GpkDbus *d
 	}
 
 	/* get command line from proc */
+#ifdef __FreeBSD__
+	mib[0] = CTL_KERN;
+	mib[1] = KERN_PROC;
+	mib[2] = KERN_PROC_PATHNAME;
+	mib[3] = pid;
+
+	len = 0;
+
+	error2 = sysctl(mib, 4, NULL, &len, NULL, 0);
+	if (error2) {
+		printf ("Error: %s\n", strerror(error2));
+		goto out;
+	}
+
+	filename = malloc(len);
+	error2 = sysctl(mib, 4, filename, &len, NULL, 0);
+	if (error2) {
+		printf ("Error: %s\n", strerror(error2));
+		goto out;
+	}
+#else
 	filename = g_strdup_printf ("/proc/%i/exe", pid);
+#endif
 	cmdline = g_file_read_link (filename, &error);
 	if (cmdline == NULL) {
 		egg_warning ("failed to find exec: %s", error->message);
