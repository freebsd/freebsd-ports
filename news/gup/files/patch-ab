--- rfc822.h.orig	Sun Oct 20 16:57:18 2002
+++ rfc822.h	Sun Oct 20 16:57:33 2002
@@ -243,12 +243,14 @@
 extern char	*strerror();
 
 /* Variables and routines that Unix(tm) provides. */
+#ifndef __FreeBSD__
 extern int	errno;
 extern int	sys_nerr;
 extern int	optind;
 extern char	*sys_errlist[];
 extern char	**environ;
 extern char	*optarg;
+#endif
 
 #ifdef HAVE_UNISTD
 #include <unistd.h>
