--- src/sp_spell.C.orig	Mon Aug 12 19:25:50 2002
+++ src/sp_spell.C	Fri Aug 23 03:38:09 2002
@@ -379,7 +379,7 @@
 		// Configure provides us with macros which are supposed to do
 		// the right typecast.
 		retval = select(SELECT_TYPE_ARG1 (pipeout[0]+1),
-				SELECT_TYPE_ARG234 (&infds),
+				&infds,
 				0,
 				0,
 				SELECT_TYPE_ARG5 (&tv));
