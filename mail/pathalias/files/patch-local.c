--- local.c.orig	1993-03-03 22:10:02.000000000 +0100
+++ local.c	2013-06-16 15:45:27.000000000 +0200
@@ -1,11 +1,9 @@
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
@@ -29,7 +27,7 @@
 	extern int gethostname();
 
 	(void) gethostname(lname, (int) sizeof(lname));
-	lname[sizeof(lname)] = 0;
+	lname[sizeof(lname) -1] = 0;
 	return(lname);
 }
 
