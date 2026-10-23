Description: Execute the version file in an explicit namespace; locals() no
  longer sees exec() results on Python 3.13 (PEP 667). Also build with
  C++20, which current pytorch requires.
Issue ID: https://github.com/open-mmlab/mmcv/issues/3341 (C++20)
Changeset: none
TODO: Submit the get_version() fix upstream; drop once a release includes
  both.

--- setup.py.orig	2024-04-24 14:24:15 UTC
+++ setup.py
@@ -38,9 +38,10 @@ def get_version():
 
 def get_version():
     version_file = 'mmcv/version.py'
+    ns = {}
     with open(version_file, encoding='utf-8') as f:
-        exec(compile(f.read(), version_file, 'exec'))
-    return locals()['__version__']
+        exec(compile(f.read(), version_file, 'exec'), ns)
+    return ns['__version__']
 
 
 def parse_requirements(fname='requirements/runtime.txt', with_version=True):
@@ -159,7 +160,7 @@ def get_extensions():
         cuda_args = os.getenv('MMCV_CUDA_ARGS')
         extra_compile_args = {
             'nvcc': [cuda_args, '-std=c++14'] if cuda_args else ['-std=c++14'],
-            'cxx': ['-std=c++14'],
+            'cxx': ['-std=c++20'],
         }
         if torch.cuda.is_available() or os.getenv('FORCE_CUDA', '0') == '1':
             define_macros += [('MMCV_WITH_CUDA', None)]
@@ -204,12 +205,12 @@ def get_extensions():
             if parse_version(torch.__version__) <= parse_version('1.12.1'):
                 extra_compile_args['cxx'] = ['-std=c++14']
             else:
-                extra_compile_args['cxx'] = ['-std=c++17']
+                extra_compile_args['cxx'] = ['-std=c++20']
         else:
             if parse_version(torch.__version__) <= parse_version('1.12.1'):
                 extra_compile_args['cxx'] = ['/std:c++14']
             else:
-                extra_compile_args['cxx'] = ['/std:c++17']
+                extra_compile_args['cxx'] = ['/std:c++20']
 
         include_dirs = []
         library_dirs = []
@@ -379,7 +380,7 @@ def get_extensions():
 
             define_macros += [('MMCV_WITH_MPS', None)]
             extra_compile_args = {}
-            extra_compile_args['cxx'] = ['-Wall', '-std=c++17']
+            extra_compile_args['cxx'] = ['-Wall', '-std=c++20']
             extra_compile_args['cxx'] += [
                 '-framework', 'Metal', '-framework', 'Foundation'
             ]
@@ -441,7 +442,7 @@ def get_extensions():
             if parse_version(torch.__version__) <= parse_version('1.12.1'):
                 extra_compile_args['nvcc'] += ['-std=c++14']
             else:
-                extra_compile_args['nvcc'] += ['-std=c++17']
+                extra_compile_args['nvcc'] += ['-std=c++20']
 
         ext_ops = extension(
             name=ext_name,
