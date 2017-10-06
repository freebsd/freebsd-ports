--- scipy/odr/setup.py.orig	2014-02-14 04:45:18.000000000 -0800
+++ scipy/odr/setup.py	2017-03-31 14:22:52.317944000 -0700
@@ -14,7 +14,7 @@ def configuration(parent_package='', top
                     'd_mprec.f',
                     'dlunoc.f']
 
-    blas_info = get_info('blas_opt')
+    blas_info = ( get_info('blas_opt') or get_info('openblas') or get_info('atlas') )
     if blas_info:
         libodr_files.append('d_lpk.f')
     else:
