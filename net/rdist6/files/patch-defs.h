--- include/defs.h	Mon Nov  9 23:23:54 1998
+++ include/defs.h	Tue Jan 18 15:41:40 2005
@@ -17,10 +17,9 @@
 /*
  * POSIX settings
  */
-#if	defined(_POSIX_SOURCE)
 #include <unistd.h>
 #include <stdlib.h>
-#endif	/* _POSIX_SOURCE */
+#include <libgen.h>
 #include <stdio.h>
 #include <ctype.h>
 #include <errno.h>
@@ -357,7 +355,6 @@
 extern void			complain();
 extern void			docmds();
 extern void			finish();
-extern void			log();
 extern void			logmsg();
 extern void			lostconn();
 extern void			markassigned();
@@ -366,7 +363,6 @@
 extern void			runcmdspecial();
 extern void			runcommand();
 extern void			server();
-extern void			setprogname();
 extern void			sighandler();
 extern void			waitup();
 struct namelist		       *expand();
@@ -379,7 +375,9 @@
 extern void			error(char *, ...);
 extern void			fatalerr(char *, ...);
 extern void			message(int, char *, ...);
+#ifndef HAVE_SETPROCTITLE
 extern void			setproctitle(char *fmt, ...);
+#endif
 #else
 extern void			debugmsg();
 extern void			error();
