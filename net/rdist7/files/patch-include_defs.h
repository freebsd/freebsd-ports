--- include/defs.h.orig	2001-10-22 13:21:36.000000000 -0700
+++ include/defs.h	2024-03-19 16:57:51.903085000 -0700
@@ -53,6 +53,7 @@
 #if defined(HAVE_STDLIB_H)
 # include <stdlib.h>
 #endif
+#include <libgen.h>
 #include <stdio.h>
 #include <ctype.h>
 #include <errno.h>
@@ -333,7 +334,6 @@
 extern void			complain();
 extern void			docmds();
 extern void			finish();
-extern void			log();
 extern void			logmsg();
 extern void			lostconn();
 extern void			markassigned();
@@ -342,7 +342,6 @@
 extern void			runcmdspecial();
 extern void			runcommand();
 extern void			server();
-extern void			setprogname();
 extern void			sighandler();
 extern void			waitup();
 struct namelist		       *expand();
@@ -355,7 +354,9 @@
 extern void			error(char *, ...);
 extern void			fatalerr(char *, ...);
 extern void			message(int, char *, ...);
+#ifndef HAVE_SETPROCTITLE
 extern void			setproctitle(const char *fmt, ...);
+#endif
 #else
 extern void			debugmsg();
 extern void			error();
