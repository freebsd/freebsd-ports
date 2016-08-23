--- src/io-utils.c.orig	2001-02-13 23:38:06 UTC
+++ src/io-utils.c
@@ -71,7 +71,7 @@ char numb_oflo[] = "####################
 
 double __plinf;
 double __neinf;
-double __nan;
+double ___nan;
 
 char nname[] = "#NOT_A_NUMBER";
 char iname[] = "#INFINITY";
@@ -125,7 +125,7 @@ init_infinity (void)
   __neinf = divide (-1., 0.);
   (void) signal (SIGFPE, ignore_sig);
 #endif
-  __nan = __plinf + __neinf;
+  ___nan = __plinf + __neinf;
 }
 
 
