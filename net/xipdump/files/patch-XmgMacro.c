--- XmgMacro.c.orig	Mon Nov 15 10:47:25 1999
+++ XmgMacro.c	Tue Oct 10 16:10:50 2000
@@ -274,7 +274,7 @@
 #if defined(__osf__) && defined(__alpha)
 			   (ArgList)(var._a0),
 #else
-			   (ArgList)var,
+			   va_arg(var, ArgList),
 #endif
 			   total_count);
 #if XtSpecificationRelease>4  
