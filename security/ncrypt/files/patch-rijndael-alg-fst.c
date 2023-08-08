--- rijndael-alg-fst.c.orig	2023-04-11 00:20:28 UTC
+++ rijndael-alg-fst.c
@@ -9,6 +9,8 @@
 
 #include "rijndael-alg-fst.h"
 
+int ROUNDS;
+
 #define SC	((BC - 4) >> 1)
 
 #include "boxes-fst.dat"
