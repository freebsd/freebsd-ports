--- src/ispell.C.orig	Wed Nov 27 19:30:07 2002
+++ src/ispell.C	Fri Feb  7 21:20:53 2003
@@ -266,7 +266,7 @@
 	// Configure provides us with macros which are supposed to do
 	// the right typecast.
 	retval = select(SELECT_TYPE_ARG1 (pipeout[0]+1),
-			SELECT_TYPE_ARG234 (&infds),
+			&infds,
 			0,
 			0,
 			SELECT_TYPE_ARG5 (&tv));
