--- cdomso.c.orig	1998-04-02 15:29:02 UTC
+++ cdomso.c
@@ -89,7 +89,7 @@ unsigned long get_w(char *fn, short bits
 }
 
 
-real monky_stat(char *filename, char *test, int no_tests)
+void monky_stat(char *filename, char *test, int no_tests)
 {
   const real bits_pw=20, mean=pow(2, bits_pw)*exp(-2);
   const counter dim=pow(2, bits_pw-5);
