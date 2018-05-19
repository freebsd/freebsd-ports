--- build.C.orig	1997-07-03 16:54:10 UTC
+++ build.C
@@ -41,7 +41,7 @@
 
 #include "RAPID_version.H"
 
-static char rapidtag_data[] = "RAPIDTAG  file: "__FILE__"    date: "__DATE__"    time: "__TIME__;
+static char rapidtag_data[] = "RAPIDTAG  file: " __FILE__ "    date: " __DATE__ "    time: " __TIME__;
 
 // to silence the compiler's complaints about unreferenced identifiers.
 static void r1(char *f){  r1(f);  r1(rapidtag_data);  r1(rapid_version);}
@@ -419,8 +419,8 @@ box::split_recurse(int *t, int n)
       // see where it lies with respect to axdmp.
       mean_from_moment(c, RAPID_moment[in]);
       
-      if (((pR[0][0]*c[0] + pR[1][0]*c[1] + pR[2][0]*c[2]) < axdmp)
-	  && ((n!=2)) || ((n==2) && (i==0)))    
+      if ( (( (pR[0][0]*c[0] + pR[1][0]*c[1] + pR[2][0]*c[2]) < axdmp)
+	  && (n!=2)) || ((n==2) && (i==0)) )
 	{
 	  // accumulate first and second order moments for group 1
 	  accum_moment(M1, RAPID_moment[in]);
