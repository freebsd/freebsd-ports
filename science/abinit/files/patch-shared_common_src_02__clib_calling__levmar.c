--- shared/common/src/02_clib/calling_levmar.c.orig	2020-11-10 12:21:53 UTC
+++ shared/common/src/02_clib/calling_levmar.c
@@ -150,7 +150,7 @@ double opts[LM_OPTS_SZ], info[LM_INFO_SZ];
       /* invoke the optimisation function with box boundaries*/
       ret=dlevmar_bc_dif(dim_screening, coeffs, yvals, c_ncoeffs, c_nvals, \
            lower_bounds, upper_bounds, 3000, opts, info, NULL, NULL, \
-           (void *)&adata); // Box boundary conditions without Jacobian
+           NULL, (void *)&adata); // Box boundary conditions without Jacobian
     //}
   //}
   
@@ -220,7 +220,7 @@ double opts[LM_OPTS_SZ], info[LM_INFO_SZ];
       /* invoke the optimisation function with box boundaries*/
       ret=dlevmar_bc_dif(dre_and_im_screening, coeffs, yvals, c_ncoeffs, c_nvals, \
            lower_bounds, upper_bounds, 1000, opts, info, NULL, NULL, \
-           (void *)&adata); // Box boundary conditions without Jacobian
+           NULL, (void *)&adata); // Box boundary conditions without Jacobian
     //}
   //}
   
