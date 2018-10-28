--- setup.py.orig	2018-10-26 18:03:19 UTC
+++ setup.py
@@ -16,31 +16,33 @@ def get_numpy_options():
    numpy_include = numpy.get_include()
 
    # Obtain BLAS/LAPACK linking options
-   lapack_info = get_info('lapack_opt')
-   blas_info = get_info('blas_opt')
-   using_atlas = False
-   using_f77blas = False
-   using_lapack = False
-   for l in lapack_info.get('libraries', []) + blas_info.get('libraries', []):
-      if "atlas" in l: using_atlas = True
-      if "f77blas" in l: using_f77blas = True
-      if "lapack" in l: using_lapack = True
-   if using_atlas and (not using_f77blas or not using_lapack):
-      lapack_info = get_info('atlas')
-      # ATLAS notices an incomplete LAPACK by not setting language to f77
-      complete_lapack = lapack_info.get('language', "") == "f77"
-      if complete_lapack:
-         blas_info = {}
-      else:
-         # If ATLAS has an incomplete LAPACK, use a regular one
-         blas_info = get_info('atlas_blas')
-         lapack_info = get_info('lapack')
+   #lapack_info = get_info('lapack_opt')
+   #blas_info = get_info('blas_opt')
+   #using_atlas = False
+   #using_f77blas = False
+   #using_lapack = False
+   #for l in lapack_info.get('libraries', []) + blas_info.get('libraries', []):
+   #   if "atlas" in l: using_atlas = True
+   #   if "f77blas" in l: using_f77blas = True
+   #   if "lapack" in l: using_lapack = True
+   #if using_atlas and (not using_f77blas or not using_lapack):
+   #   lapack_info = get_info('atlas')
+   #   # ATLAS notices an incomplete LAPACK by not setting language to f77
+   #   complete_lapack = lapack_info.get('language', "") == "f77"
+   #   if complete_lapack:
+   #      blas_info = {}
+   #   else:
+   #      # If ATLAS has an incomplete LAPACK, use a regular one
+   #      blas_info = get_info('atlas_blas')
+   #      lapack_info = get_info('lapack')
    
-   blaslapack_libraries = lapack_info.get('libraries', []) + blas_info.get('libraries', [])
-   blaslapack_library_dirs = lapack_info.get('library_dirs', []) + blas_info.get('library_dirs', [])
-   blaslapack_extra_link_args = lapack_info.get('extra_link_args', []) + blas_info.get('extra_link_args', [])
-   if not blaslapack_libraries and not blaslapack_extra_link_args:
-       blaslapack_libraries = ['lapack', 'blas']
+   #blaslapack_libraries = lapack_info.get('libraries', []) + blas_info.get('libraries', [])
+   #blaslapack_library_dirs = lapack_info.get('library_dirs', []) + blas_info.get('library_dirs', [])
+   #blaslapack_extra_link_args = lapack_info.get('extra_link_args', []) + blas_info.get('extra_link_args', [])
+   #if not blaslapack_libraries and not blaslapack_extra_link_args:
+   blaslapack_libraries = []
+   blaslapack_extra_link_args = []
+   blaslapack_library_dirs = []
 
    r = dict(
                    include_dirs = [numpy_include, "primme/include", "primme/src/include"],
