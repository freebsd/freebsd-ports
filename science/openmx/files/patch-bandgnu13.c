--- bandgnu13.c.orig	2019-12-02 04:59:59 UTC
+++ bandgnu13.c
@@ -75,7 +75,7 @@ void vk_rtv(double vk[4], double rtv[4][4])
 
 #define MUNIT 2
 
-main(int argc, char **argv)
+int main(int argc, char **argv)
 {
   static double Unit0[MUNIT]={27.2113845,1.0}; /* Hartree-> eV */
   static char *Unitname0[MUNIT]={"eV","Hartree"};
