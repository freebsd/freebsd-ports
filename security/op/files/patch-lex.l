--- lex.l.orig	Mon Apr 15 23:30:47 2002
+++ lex.l	Mon Apr 15 23:30:18 2002
@@ -14,6 +14,7 @@
 #include <ctype.h>
 #include "defs.h"
 
+static int	addarg();
 static cmd_t	*newcmd();
 char	*savestr();
 
