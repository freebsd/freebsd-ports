--- overlap.C.orig	2018-05-16 10:58:45 UTC
+++ overlap.C
@@ -41,7 +41,7 @@
 
 #include "RAPID_version.H"
 
-static char rapidtag_data[] = "RAPIDTAG  file: "__FILE__"    date: "__DATE__"    time: "__TIME__;
+static char rapidtag_data[] = "RAPIDTAG  file: " __FILE__ "    date: " __DATE__ "    time: " __TIME__;
 
 // to silence the compiler's complaints about unreferenced identifiers.
 static void r1(char *f){  r1(f);  r1(rapidtag_data);  r1(rapid_version);}
@@ -221,8 +221,8 @@ models.
 int
 obb_disjoint(double B[3][3], double T[3], double a[3], double b[3])
 {
-  register double t, s;
-  register int r;
+  double t, s;
+  int r;
   double Bf[3][3];
   const double reps = 1e-6;
   
