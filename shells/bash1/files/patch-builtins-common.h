--- builtins/common.h.orig	Fri Aug 29 12:14:20 2003
+++ builtins/common.h	Fri Aug 29 12:14:46 2003
@@ -23,7 +23,7 @@
 
 #define ISOPTION(s, c)	(s[0] == '-' && !s[2] && s[1] == c)
 
-extern void builtin_error ();
+extern void builtin_error (char *, ...);
 extern void bad_option ();
 
 extern int get_numeric_arg ();
