--- src/misc.h.orig	Sat Jun 19 01:20:20 2004
+++ src/misc.h	Sat Jun 19 01:28:26 2004
@@ -37,6 +37,13 @@
 
 extern void die( char *msg );
 
+/*
+ * XXX Nasty hack to work around a namespace conflict on the round(3)
+ * function.  This is legal as long as all sources that include this
+ * header as well as <math.h> include <math.h> first.
+ */
+#undef round
+#define	round	myround
 extern float round( float x );
 
 extern int which( char *file, char *fullpath );
