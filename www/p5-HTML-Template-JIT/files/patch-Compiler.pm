--- Compiler.pm.orig	Tue May 18 18:32:59 2004
+++ JIT/Compiler.pm	Tue May 18 18:33:52 2004
@@ -131,7 +131,7 @@
   SV * temp_sv;
   int i;
   STRLEN len;
-  char c;
+  unsigned char c;
   char buf[4];
 
   SvPOK_on(result);
