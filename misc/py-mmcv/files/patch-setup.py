-- latest pytorch requires c++20: https://github.com/open-mmlab/mmcv/issues/3341

--- setup.py.orig	2024-04-24 14:24:15 UTC
+++ setup.py
@@ -159,7 +159,7 @@ def get_extensions():
         cuda_args = os.getenv('MMCV_CUDA_ARGS')
         extra_compile_args = {
             'nvcc': [cuda_args, '-std=c++14'] if cuda_args else ['-std=c++14'],
-            'cxx': ['-std=c++14'],
+            'cxx': ['-std=c++20'],
         }
         if torch.cuda.is_available() or os.getenv('FORCE_CUDA', '0') == '1':
             define_macros += [('MMCV_WITH_CUDA', None)]
@@ -204,12 +204,12 @@ def get_extensions():
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
@@ -379,7 +379,7 @@ def get_extensions():
 
             define_macros += [('MMCV_WITH_MPS', None)]
             extra_compile_args = {}
-            extra_compile_args['cxx'] = ['-Wall', '-std=c++17']
+            extra_compile_args['cxx'] = ['-Wall', '-std=c++20']
             extra_compile_args['cxx'] += [
                 '-framework', 'Metal', '-framework', 'Foundation'
             ]
@@ -441,7 +441,7 @@ def get_extensions():
             if parse_version(torch.__version__) <= parse_version('1.12.1'):
                 extra_compile_args['nvcc'] += ['-std=c++14']
             else:
-                extra_compile_args['nvcc'] += ['-std=c++17']
+                extra_compile_args['nvcc'] += ['-std=c++20']
 
         ext_ops = extension(
             name=ext_name,
