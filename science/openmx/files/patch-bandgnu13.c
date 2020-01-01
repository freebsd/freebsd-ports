--- bandgnu13.c.orig	2018-09-11 19:33:10 UTC
+++ bandgnu13.c
@@ -75,7 +75,7 @@ void vk_rtv(double vk[4], double rtv[4][
 
 #define MUNIT 2
 
-main(int argc, char **argv)
+int main(int argc, char **argv)
 {
   static double Unit0[MUNIT]={27.2,1.0}; /* Hartree-> eV */
   static char *Unitname0[MUNIT]={"eV","Hartree"};
