--- spunk/xsrc/console.cc.orig	Sat Feb 26 17:48:40 2000
+++ spunk/xsrc/console.cc	Sat Feb 26 17:49:13 2000
@@ -374,7 +374,7 @@
 // the parameter following this name and remove both from the argument list.
 {
     // Get the argument vector
-    const char** Args = GetArgVec ();
+    const char** Args = (const char **)GetArgVec ();
 
     // search for the given argument
     int I = 1;
