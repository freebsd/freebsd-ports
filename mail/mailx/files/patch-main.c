--- main.c.orig	1998-03-08 09:46:57 UTC
+++ main.c
@@ -41,6 +41,8 @@ static char copyright[] =
 static char sccsid[] = "@(#)main.c	8.1 (Berkeley) 6/6/93";
 #endif /* not lint */
 
+#define IN_MAIN
+
 #include "rcv.h"
 #include <err.h>
 #include <fcntl.h>
