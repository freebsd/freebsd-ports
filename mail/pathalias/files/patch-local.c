--- local.c.orig	1993-03-03 22:10:02.000000000 +0100
+++ local.c	2013-06-16 18:29:55.000000000 +0200
@@ -1,15 +1,14 @@
 /* pathalias -- by steve bellovin, as told to peter honeyman */
 #ifndef lint
-static char	*sccsid = "@(#)local.c	9.3 91/06/11";
+static const char	*sccsid = "@(#)local.c	9.3 91/06/11";
 #endif /* lint */
 
-#include "config.h"
-
-#include STDIO_H
+#include "def.h"
 
 #ifdef	UNAME
 #include <sys/utsname.h>
 
+
 char	*
 local()
 {
@@ -22,14 +21,17 @@
 
 #else /* !UNAME */
 
+#ifndef GETHOSTNAME
+STATIC int gethostname(char *name, int len);
+#endif /* GETHOSTNAME */
+
 char	*
 local()
 {
 	static char lname[64];
-	extern int gethostname();
 
 	(void) gethostname(lname, (int) sizeof(lname));
-	lname[sizeof(lname)] = 0;
+	lname[sizeof(lname) -1] = 0;
 	return(lname);
 }
 
