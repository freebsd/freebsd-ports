--- include/defs.h.orig	1998-11-10 04:23:54 UTC
+++ include/defs.h
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
@@ -357,7 +356,6 @@ extern void			cleanup();
 extern void			complain();
 extern void			docmds();
 extern void			finish();
-extern void			log();
 extern void			logmsg();
 extern void			lostconn();
 extern void			markassigned();
@@ -366,7 +364,6 @@ extern void			note();
 extern void			runcmdspecial();
 extern void			runcommand();
 extern void			server();
-extern void			setprogname();
 extern void			sighandler();
 extern void			waitup();
 struct namelist		       *expand();
@@ -379,7 +376,9 @@ extern void			debugmsg(int, char *, ...);
 extern void			error(char *, ...);
 extern void			fatalerr(char *, ...);
 extern void			message(int, char *, ...);
+#ifndef HAVE_SETPROCTITLE
 extern void			setproctitle(char *fmt, ...);
+#endif
 #else
 extern void			debugmsg();
 extern void			error();
