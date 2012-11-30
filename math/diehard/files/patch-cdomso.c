--- cdomso.c.orig	2012-11-30 16:01:24.000000000 +0100
+++ cdomso.c	2012-11-30 16:02:15.000000000 +0100
@@ -89,7 +89,7 @@
 }
 
 
-real monky_stat(char *filename, char *test, int no_tests)
+void monky_stat(char *filename, char *test, int no_tests)
 {
   const real bits_pw=20, mean=pow(2, bits_pw)*exp(-2);
   const counter dim=pow(2, bits_pw-5);
