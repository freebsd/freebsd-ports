--- src/io-utils.c.org	Sat Jul 19 13:42:11 2003
+++ src/io-utils.c	Sat Jul 19 13:48:32 2003
@@ -71,7 +71,7 @@
 
 double __plinf;
 double __neinf;
-double __nan;
+double ___nan;
 
 char nname[] = "#NOT_A_NUMBER";
 char iname[] = "#INFINITY";
@@ -125,7 +125,7 @@
   __neinf = divide (-1., 0.);
   (void) signal (SIGFPE, ignore_sig);
 #endif
-  __nan = __plinf + __neinf;
+  ___nan = __plinf + __neinf;
 }
 
 
