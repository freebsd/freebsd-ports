--- pyfr/backends/openmp/compiler.py.orig	2018-03-19 21:34:24 UTC
+++ pyfr/backends/openmp/compiler.py
@@ -76,6 +76,8 @@ class SourceModule(object):
             '-Ofast',               # Optimise, incl. -ffast-math
             '-march=native',        # Use CPU-specific instructions
             '-fopenmp',             # Enable OpenMP support
+            '-I%%LOCALBASE%%/include',  # Add the include directory
+            '-L%%LOCALBASE%%/lib',  # Add the library directory
             '-fPIC',                # Generate position-independent code
             '-o', libname, srcname, # Library and source file names
             '-lm'                   # Link against libm
