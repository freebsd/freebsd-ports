--- setup.py.orig	2018-05-13 20:38:06 UTC
+++ setup.py
@@ -253,7 +253,7 @@ def extensions(config):
     use_cython = config.get('use_cython', default=not is_release)
     use_openmp = config.get('use_openmp', default=True)
 
-    extra_compile_args = ['-std=c99', '-ffast-math', '-O3', '-funroll-loops']
+    extra_compile_args = ['-std=c99', '-ffast-math', '-funroll-loops']
     define_macros = []
     if config.get('debug_cflags', default=False):
         extra_compile_args.extend(['-Wall', '-pedantic'])
