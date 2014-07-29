--- config/os-freebsd2.h	Mon Nov  9 22:59:55 1998
+++ config/os-freebsd2.h	Tue Jan 18 15:13:07 2005
@@ -116,18 +116,23 @@
  */
 #define HAVE_FCHOWN			/* Have fchown() */
 #define HAVE_FCHMOD			/* Have fchmod() */
+#define HAVE_FTRUNCATE			/* Have ftruncate() */
+#define HAVE_PATHS_H			/* Have paths.h */
 #define HAVE_SELECT			/* Have select() */
 #define HAVE_SAVED_IDS			/* Have POSIX style saved [ug]id's */
+#define HAVE_SETPROCTITLE		/* has a native setproctitle() */
 #define POSIX_SIGNALS			/* Have POSIX signals */
 
 /*
  * Things we need
  */
 #define NEED_UNISTD_H			/* Need <unistd.h> */
+#define NEED_STRING_H			/* Need <string.h> -- for strerror(3) */
 
 /*
  * Path to the remote shell command.
  * Define this only if the pathname is different than
  * that which appears in "include/paths.h".
  */
-#define _PATH_REMSH	"/usr/bin/rsh"			/**/
+#define _PATH_REMSH	"/usr/bin/ssh"			/**/
+#define _PATH_OLDRDIST	"/usr/bin/rdist"	/* Enable compat */
