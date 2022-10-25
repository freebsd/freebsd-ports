--- pyscf/lib/dft/libxc_itrf.c.orig	2022-09-03 00:05:50 UTC
+++ pyscf/lib/dft/libxc_itrf.c
@@ -453,7 +453,7 @@ int LIBXC_is_hybrid(int xc_id)
                 raise_error -1;
         }
 
-#if XC_MAJOR_VERSION < 6
+#if XC_MAJOR_VERSION <= 6
         switch(func.info->family)
         {
 #ifdef XC_FAMILY_HYB_LDA
@@ -483,7 +483,7 @@ double LIBXC_hybrid_coeff(int xc_id)
                 raise_error 0.0;
         }
 
-#if XC_MAJOR_VERSION < 6
+#if XC_MAJOR_VERSION <= 6
         switch(func.info->family)
         {
 #ifdef XC_FAMILY_HYB_LDA
@@ -530,7 +530,7 @@ void LIBXC_rsh_coeff(int xc_id, double *rsh_pars) {
         rsh_pars[1] = 0.0;
         rsh_pars[2] = 0.0;
 
-#if XC_MAJOR_VERSION < 6
+#if XC_MAJOR_VERSION <= 6
         XC(hyb_cam_coef)(&func, &rsh_pars[0], &rsh_pars[1], &rsh_pars[2]);
 #else
         switch(xc_hyb_type(&func)) {
@@ -548,7 +548,7 @@ int LIBXC_is_cam_rsh(int xc_id) {
                 fprintf(stderr, "XC functional %d not found\n", xc_id);
                 raise_error -1;
         }
-#if XC_MAJOR_VERSION < 6
+#if XC_MAJOR_VERSION <= 6
         int is_cam = func.info->flags & XC_FLAGS_HYB_CAM;
 #else
         int is_cam = (xc_hyb_type(&func) == XC_HYB_CAM);
@@ -793,7 +793,7 @@ void LIBXC_eval_xc(int nfn, int *fn_id, double *fac, d
                 // set the range-separated parameter
                 if (omega[i] != 0) {
                         // skip if func is not a RSH functional
-#if XC_MAJOR_VERSION < 6
+#if XC_MAJOR_VERSION <= 6
                         if (func.cam_omega != 0) {
                                 func.cam_omega = omega[i];
                         }
@@ -805,7 +805,7 @@ void LIBXC_eval_xc(int nfn, int *fn_id, double *fac, d
                         // Recursively set the sub-functionals if they are RSH
                         // functionals
                         for (j = 0; j < func.n_func_aux; j++) {
-#if XC_MAJOR_VERSION < 6
+#if XC_MAJOR_VERSION <= 6
                                 if (func.func_aux[j]->cam_omega != 0) {
                                         func.func_aux[j]->cam_omega = omega[i];
                                 }
