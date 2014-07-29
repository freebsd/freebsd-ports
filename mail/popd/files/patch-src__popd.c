Index: src/popd.c
diff -u -p src/popd.c.orig src/popd.c
--- src/popd.c.orig	Fri Jan 24 21:01:25 2003
+++ src/popd.c	Wed Jun  1 09:00:55 2005
@@ -54,6 +54,10 @@
 #include "signals.h"
 #include "proxy.h"
 
+#ifndef NI_WITHSCOPEID
+#define NI_WITHSCOPEID	0
+#endif
+
 /* global variables */
 extern FILE		*yyin;
 extern int		 yyparse(void);
