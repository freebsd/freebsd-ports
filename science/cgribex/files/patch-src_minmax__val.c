--- src/minmax_val.c.orig	2022-03-21 21:31:13 UTC
+++ src/minmax_val.c
@@ -303,8 +303,8 @@ void pwr6_minmax_val_double_unrolled6(const double *re
     size_t i, j;
     size_t residual =  datasize % __UNROLL_DEPTH_1;
     size_t ofs = datasize - residual;
-    double register dmin[__UNROLL_DEPTH_1];
-    double register dmax[__UNROLL_DEPTH_1];
+    double dmin[__UNROLL_DEPTH_1];
+    double dmax[__UNROLL_DEPTH_1];
 
     for ( j = 0; j < __UNROLL_DEPTH_1; j++) 
       {
@@ -316,21 +316,21 @@ void pwr6_minmax_val_double_unrolled6(const double *re
       {
 	for (j = 0; j < __UNROLL_DEPTH_1; j++) 
 	  {
-	    dmin[j] = __fsel(dmin[j] - data[i+j], data[i+j], dmin[j]);
-	    dmax[j] = __fsel(data[i+j] - dmax[j], data[i+j], dmax[j]);
+	    dmin[j] = __builtin_ppc_fsel(dmin[j] - data[i+j], data[i+j], dmin[j]);
+	    dmax[j] = __builtin_ppc_fsel(data[i+j] - dmax[j], data[i+j], dmax[j]);
 	  }
       }
 
     for (j = 0; j < residual; j++) 
       {
-	dmin[j] = __fsel(dmin[j] - data[ofs+j], data[ofs+j], dmin[j]);
-	dmax[j] = __fsel(data[ofs+j] - dmax[j], data[ofs+j], dmax[j]);
+	dmin[j] = __builtin_ppc_fsel(dmin[j] - data[ofs+j], data[ofs+j], dmin[j]);
+	dmax[j] = __builtin_ppc_fsel(data[ofs+j] - dmax[j], data[ofs+j], dmax[j]);
       }
 
     for ( j = 0; j < __UNROLL_DEPTH_1; j++) 
       {
-	*fmin = __fsel(*fmin - dmin[j], dmin[j], *fmin);
-	*fmax = __fsel(dmax[j] - *fmax, dmax[j], *fmax);
+	*fmin = __builtin_ppc_fsel(*fmin - dmin[j], dmin[j], *fmin);
+	*fmax = __builtin_ppc_fsel(dmax[j] - *fmax, dmax[j], *fmax);
       }
   }
 #undef __UNROLL_DEPTH_1
