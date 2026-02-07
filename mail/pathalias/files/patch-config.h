--- config.h.orig	1993-03-03 22:10:30.000000000 +0100
+++ config.h	2013-06-16 23:36:45.000000000 +0200
@@ -29,7 +29,7 @@
 
 #ifdef MAIN
 #ifndef lint
-static char	*c_sccsid = "@(#)config.h	9.5 91/06/11";
+static const char	*c_sccsid = "@(#)config.h	9.5 91/06/11";
 #endif /*lint*/
 #endif /*MAIN*/
 
@@ -64,6 +64,9 @@
 #define	CTYPE_H		ctype
 #endif
 
+#include <stdlib.h>
+#include <string.h>
+
 /*
  * malloc/free fine tuned for pathalias.
  *
@@ -79,9 +82,7 @@
 #define calloc(n, s) malloc ((n)*(s))
 #define free(s)
 #define cfree(s)
-extern char *memget();
 #else /* !MYMALLOC */
-extern char *calloc();
 #endif /* MYMALLOC */
 
 #ifdef STRCHR
@@ -105,9 +106,6 @@
 
 #endif /*BZERO*/
 
-extern char	*malloc();
-extern char	*strcpy(), *index(), *rindex();
-
 #ifndef STATIC
 
 #ifdef DEBUG
