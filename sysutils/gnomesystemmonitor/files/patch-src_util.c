--- src/util.c.orig	Fri Dec 12 02:26:57 2003
+++ src/util.c	Fri Dec 12 02:35:38 2003
@@ -16,6 +16,7 @@
 
 #ifdef __FreeBSD__
 # include <errno.h>
+# include <termios.h>
 # include <libutil.h>
 #endif
 
@@ -181,7 +182,11 @@
 	 * Make su think we're sending the password from a terminal:
 	 */
 
+#ifndef __FreeBSD__
 	if (((t_fd = OPEN_TTY()) < 0) || (grantpt(t_fd) < 0) || (unlockpt(t_fd) < 0)) {
+#else
+	if ((t_fd = OPEN_TTY()) < 0) {
+#endif
 		fprintf (stderr, "Unable to open a terminal\n");
 		ABORT (root);
 	}
@@ -259,7 +264,11 @@
 			}
 		}
 
+#ifndef __FreeBSD__
 		if(((pts = ptsname(t_fd)) == NULL) || ((t_fd = open(pts, O_RDWR | O_NOCTTY)) < 0)) {
+#else
+		if (((pts = ttyname(t_fd)) == NULL) || ((t_fd = open(pts, O_RDWR | O_NOCTTY)) < 0)) {
+#endif
 			perror ("Unable to open pseudo slave terminal");
 			_exit (-1);
 		}
