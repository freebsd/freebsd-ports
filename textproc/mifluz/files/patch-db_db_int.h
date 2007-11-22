--- db/db_int.h.orig	2007-11-22 12:18:53.000000000 +0100
+++ db/db_int.h	2007-11-22 12:24:32.000000000 +0100
@@ -108,10 +108,10 @@
  * an array.
  */
 #undef	SSZ
-#define	SSZ(name, field)	((int)&(((name *)0)->field))
+#define	SSZ(name, field)	((size_t)&(((name *)0)->field))
 
 #undef	SSZA
-#define	SSZA(name, field)	((int)&(((name *)0)->field[0]))
+#define	SSZA(name, field)	((size_t)&(((name *)0)->field[0]))
 
 /*
  * Print an address as a u_long (a u_long is the largest type we can print
