--- src/minmax_val.c.orig	2024-10-23 07:38:19 UTC
+++ src/minmax_val.c
@@ -322,21 +322,21 @@ pwr6_minmax_val_double_unrolled6(const double *restric
       {
         for (size_t j = 0; j < __UNROLL_DEPTH_1; ++j)
           {
-            dmin[j] = __fsel(dmin[j] - data[i + j], data[i + j], dmin[j]);
-            dmax[j] = __fsel(data[i + j] - dmax[j], data[i + j], dmax[j]);
+            dmin[j] = __builtin_ppc_fsel(dmin[j] - data[i + j], data[i + j], dmin[j]);
+            dmax[j] = __builtin_ppc_fsel(data[i + j] - dmax[j], data[i + j], dmax[j]);
           }
       }
 
     for (size_t j = 0; j < residual; ++j)
       {
-        dmin[j] = __fsel(dmin[j] - data[ofs + j], data[ofs + j], dmin[j]);
-        dmax[j] = __fsel(data[ofs + j] - dmax[j], data[ofs + j], dmax[j]);
+        dmin[j] = __builtin_ppc_fsel(dmin[j] - data[ofs + j], data[ofs + j], dmin[j]);
+        dmax[j] = __builtin_ppc_fsel(data[ofs + j] - dmax[j], data[ofs + j], dmax[j]);
       }
 
     for (size_t j = 0; j < __UNROLL_DEPTH_1; ++j)
       {
-        *fmin = __fsel(*fmin - dmin[j], dmin[j], *fmin);
-        *fmax = __fsel(dmax[j] - *fmax, dmax[j], *fmax);
+        *fmin = __builtin_ppc_fsel(*fmin - dmin[j], dmin[j], *fmin);
+        *fmax = __builtin_ppc_fsel(dmax[j] - *fmax, dmax[j], *fmax);
       }
   }
 #undef __UNROLL_DEPTH_1
