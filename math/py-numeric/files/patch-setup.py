--- setup.py.orig	Wed Sep 29 01:50:45 2004
+++ setup.py	Wed Oct 20 09:31:06 2004
@@ -33,21 +33,21 @@
 
 # delete all but the first one in this list if using your own LAPACK/BLAS
 sourcelist = [os.path.join('Src', 'lapack_litemodule.c'),
-#              os.path.join('Src', 'blas_lite.c'), 
-#              os.path.join('Src', 'f2c_lite.c'), 
-#              os.path.join('Src', 'zlapack_lite.c'),
-#              os.path.join('Src', 'dlapack_lite.c')
+              os.path.join('Src', 'blas_lite.c'), 
+              os.path.join('Src', 'f2c_lite.c'), 
+              os.path.join('Src', 'zlapack_lite.c'),
+              os.path.join('Src', 'dlapack_lite.c')
              ]
 # set these to use your own BLAS;
 
-library_dirs_list = ['/usr/lib/atlas']
-libraries_list = ['lapack', 'cblas', 'f77blas', 'atlas', 'g2c'] 
+library_dirs_list = []
+libraries_list = [] 
                    # if you also set `use_dotblas` (see below), you'll need:
                    # ['lapack', 'cblas', 'f77blas', 'atlas', 'g2c']
 
 # set to true (1), if you also want BLAS optimized matrixmultiply/dot/innerproduct
-use_dotblas = 1
-include_dirs = ['/usr/include/atlas']  # You may need to set this to find cblas.h
+use_dotblas = 0
+include_dirs = []  # You may need to set this to find cblas.h
                    #  e.g. on UNIX using ATLAS this should be ['/usr/include/atlas'] 
 
 # The packages are split in this way to allow future optional inclusion
