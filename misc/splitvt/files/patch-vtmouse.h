--- vtmouse.h.orig	Sat Oct  7 02:22:11 2006
+++ vtmouse.h	Sat Oct  7 02:22:36 2006
@@ -39,5 +39,5 @@
 extern int  event_getc();
 extern void event_quit();
 
-extern FILE *xt_input, *xt_output;	/* Usually untouched */
+static FILE *xt_input, *xt_output;	/* Usually untouched */
 
