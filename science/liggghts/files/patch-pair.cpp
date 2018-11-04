--- pair.cpp.orig	2018-11-02 06:56:59 UTC
+++ pair.cpp
@@ -566,7 +566,7 @@ void Pair::init_tables_disp(double cut_l
     }
     
     rsq = rsq_lookup.f;
-    register double x2 = g2*rsq, a2 = 1.0/x2;
+    double x2 = g2*rsq, a2 = 1.0/x2;
     x2 = a2*exp(-x2);
 
     rdisptable[i] = rsq_lookup.f;
@@ -612,7 +612,7 @@ void Pair::init_tables_disp(double cut_l
   if (rsq_lookup.f < (cut_lj_globalsq = cut_lj_global * cut_lj_global)) {
     rsq_lookup.f = cut_lj_globalsq;
     
-    register double x2 = g2*rsq, a2 = 1.0/x2;
+    double x2 = g2*rsq, a2 = 1.0/x2;
     x2 = a2*exp(-x2);
     f_tmp = g8*(((6.0*a2+6.0)*a2+3.0)*a2+1.0)*x2*rsq;
     e_tmp = g6*((a2+1.0)*a2+0.5)*x2;
