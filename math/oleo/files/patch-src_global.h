--- src/global.h.org	Thu Feb 15 05:54:50 2001
+++ src/global.h	Sat Jul 19 13:45:39 2003
@@ -208,7 +208,7 @@
 extern char nname[];
 
 extern VOIDSTAR parse_hash;
-extern double __plinf, __neinf, __nan;
+extern double __plinf, __neinf, ___nan;
 
 /* These have two uses.  During parsing, these contain the 
  * base address of all relative references.  During evaluation,
