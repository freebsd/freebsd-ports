--- setup.py.orig	2023-12-26 20:45:53 UTC
+++ setup.py
@@ -266,7 +266,7 @@ def extensions(config):
     use_openmp = config.get('use_openmp', default=True)
     annotate_cython = config.get('annotate_cython', default=False)
 
-    extra_compile_args = ['-std=c99', '-O3', '-funroll-loops',
+    extra_compile_args = ['-std=c99', '-funroll-loops',
                           '-fsigned-zeros'] # see #2722
     define_macros = []
     if config.get('debug_cflags', default=False):
@@ -598,7 +598,6 @@ if __name__ == '__main__':
           'scipy>=1.5.0',
           'matplotlib>=1.5.1',
           'tqdm>=4.43.0',
-          'threadpoolctl',
           'packaging',
           'fasteners',
           'mda-xdrlib',
