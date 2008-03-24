--- src/ck-sysdeps-unix.c.orig	2008-02-06 22:59:55.000000000 -0500
+++ src/ck-sysdeps-unix.c	2008-02-06 22:52:34.000000000 -0500
@@ -172,6 +172,15 @@ ck_get_a_console_fd (void)
 
         fd = -1;
 
+#ifdef __FreeBSD__
+	/* On FreeBSD, try /dev/consolectl first as this will survive
+	 * /etc/ttys initialization. */
+	fd = open_a_console ("/dev/consolectl");
+	if (fd >= 0) {
+		goto done;
+	}
+#endif
+
 #ifdef __sun
         /* On Solaris, first try Sun VT device. */
         fd = open_a_console ("/dev/vt/active");
