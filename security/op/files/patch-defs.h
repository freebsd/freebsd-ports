--- defs.h.orig	Sun Nov 23 01:11:52 1997
+++ defs.h	Tue Jan 30 09:45:22 2001
@@ -19,4 +19,6 @@
 extern cmd_t	*First, *Build();
 
 #define MAXSTRLEN	256
+#ifndef OP_ACCESS
 #define OP_ACCESS	"/usr/local/etc/op.access"
+#endif
