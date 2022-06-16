--- setup.py.orig	2022-06-02 18:49:09 UTC
+++ setup.py
@@ -274,7 +274,7 @@ def extensions(config):
     use_cython = config.get('use_cython', default=cython_found)
     use_openmp = config.get('use_openmp', default=True)
 
-    extra_compile_args = ['-std=c99', '-ffast-math', '-O3', '-funroll-loops',
+    extra_compile_args = ['-std=c99', '-ffast-math', '-funroll-loops',
                           '-fsigned-zeros'] # see #2722
     define_macros = []
     if config.get('debug_cflags', default=False):
@@ -599,7 +599,6 @@ if __name__ == '__main__':
           'scipy>=1.5.0',
           'matplotlib>=1.5.1',
           'tqdm>=4.43.0',
-          'threadpoolctl',
           'packaging',
           'fasteners',
           'gsd>=1.9.3',
