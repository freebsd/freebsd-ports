--- clientserver.c	7 Feb 2002 16:36:12 -0000	1.82
+++ clientserver.c	21 Feb 2002 00:45:48 -0000	1.86
@@ -282,6 +285,24 @@
 	}
 
 	if (am_root) {
+		/* Get rid of any supplementary groups this process
+		 * might have inheristed. */
+		if (setgroups(0, NULL)) {
+			rsyserr(FERROR, errno, "setgroups failed");
+			io_printf(fd, "@ERROR: setgroups failed\n");
+			return -1;
+		}
+
+		/* XXXX: You could argue that if the daemon is started
+		 * by a non-root user and they explicitly specify a
+		 * gid, then we should try to change to that gid --
+		 * this could be possible if it's already in their
+		 * supplementary groups. */
+
+		/* TODO: Perhaps we need to document that if rsyncd is
+		 * started by somebody other than root it will inherit
+		 * all their supplementary groups. */
+
 		if (setgid(gid)) {
 			rsyserr(FERROR, errno, "setgid %d failed", (int) gid);
 			io_printf(fd,"@ERROR: setgid failed\n");
