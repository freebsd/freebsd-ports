--- maskgen.c.orig	1992-01-17 19:14:43 UTC
+++ maskgen.c
@@ -2,11 +2,11 @@
 #include "agrep.h"
  
 extern unsigned D_endpos, endposition, Init1, wildmask;
-extern Mask[], Bit[], Init[], NO_ERR_MASK;
+extern int Mask[], Bit[], Init[], NO_ERR_MASK;
 extern int AND, SIMPLEPATTERN, REGEX, NOUPPER, D_length;
 extern unsigned char Progname[];
 	   
-maskgen(Pattern, D)
+int maskgen(Pattern, D)
 unsigned char *Pattern; int D;
 {
 struct term { int flag; unsigned char class[WORD];
