--- setup.py.orig	Wed Jan 12 12:46:37 2005
+++ setup.py	Wed Jan 12 12:48:15 2005
@@ -33,19 +33,19 @@
 
 # delete all but the first one in this list if using your own LAPACK/BLAS
 sourcelist = [os.path.join('Src', 'lapack_litemodule.c'),
-              #os.path.join('Src', 'blas_lite.c'), 
-              #os.path.join('Src', 'f2c_lite.c'), 
-              #os.path.join('Src', 'zlapack_lite.c'),
-              #os.path.join('Src', 'dlapack_lite.c')
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
 
 # set to true (1), if you also want BLAS optimized matrixmultiply/dot/innerproduct
-use_dotblas = 1 
-include_dirs = ['/usr/include/atlas']  
+use_dotblas = 0 
+include_dirs = []  
                    # You may need to set this to find cblas.h
                    #  e.g. on UNIX using ATLAS this should be ['/usr/include/atlas']
 extra_link_args = []
