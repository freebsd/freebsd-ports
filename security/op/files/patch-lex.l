--- lex.l.orig	Wed Oct 15 05:58:41 2003
+++ lex.l	Wed Oct 15 06:01:15 2003
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
 
@@ -47,20 +48,15 @@
 #include <sys/stat.h>
 #include <syslog.h>
 
-msg(va_alist)
- va_dcl
+msg(char *s,...)
 {
-#if 0
 	va_list	ap;
-	char	*s;
 
-	va_start(ap);
-	s = va_arg(ap, char *);
+	va_start(ap,s);
 	fprintf(stderr,"line %d: ",yyline);
 	vfprintf(stderr, s, ap);
 	fputc('\n', stderr);
 	va_end(ap);
-#endif
 }
 
 static addarg(state, cmd, str)
