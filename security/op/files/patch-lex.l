--- lex.l.orig	Thu Mar  3 20:47:59 2005
+++ lex.l	Thu Mar  3 20:49:11 2005
@@ -10,10 +10,11 @@
 /* +-------------------------------------------------------------------+ */
 
 #include <stdio.h>
-#include <varargs.h>
+#include <stdarg.h>
 #include <ctype.h>
 #include "defs.h"
 
+static int	addarg();
 static cmd_t	*newcmd();
 char	*savestr();
 
@@ -47,15 +48,12 @@
 #include <sys/stat.h>
 #include <syslog.h>
 
-msg(va_alist)
- va_dcl
+msg (char *s, ...)
 {
 #if 0
 	va_list	ap;
-	char	*s;
 
-	va_start(ap);
-	s = va_arg(ap, char *);
+	va_start(ap,s);
 	fprintf(stderr,"line %d: ",yyline);
 	vfprintf(stderr, s, ap);
 	fputc('\n', stderr);
