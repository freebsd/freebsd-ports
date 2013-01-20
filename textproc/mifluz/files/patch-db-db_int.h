--- ./db/db_int.h.orig	2013-01-16 13:43:03.627123979 +0800
+++ ./db/db_int.h	2013-01-16 13:49:17.653734397 +0800
@@ -108,7 +108,7 @@
  * an array.
  */
 #undef	SSZ
-#define	SSZ(name, field)	((int)&(((name *)0)->field))
+#define	SSZ(name, field)	((size_t)&(((name *)0)->field))
 
 #undef	SSZA
 #define	SSZA(name, field)	((long)&(((name *)0)->field[0]))
