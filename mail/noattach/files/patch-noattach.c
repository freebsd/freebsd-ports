--- noattach.c.orig	Wed Feb  2 12:16:45 2005
+++ noattach.c	Sun Apr 17 23:04:29 2005
@@ -77,8 +77,10 @@
 
 #ifndef true
 #ifndef SMFIF_QUARANTINE
+#ifndef __bool_true_false_are_defined
 typedef int	bool;		/* kludge: typedef unneeded in 8.13.0, when
 				 * quarantining was introduced */
+#endif
 #endif
 #define false  0
 #define true   1
