--- alloc.c.orig	Tue May 18 07:45:09 1999
+++ alloc.c	Sat Jan 11 15:11:22 2003
@@ -110,5 +110,9 @@
 	Block  *block;
 	struct {int _;} junk;	/* alignment */
+#ifdef __ia64__
+	long double djunk;	/* alignment */
+#else
 	double djunk;		/* alignment */
+#endif
 };
 
