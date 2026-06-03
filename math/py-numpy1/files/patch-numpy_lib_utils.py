--- numpy/lib/utils.py.orig	2024-02-05 21:17:48 UTC
+++ numpy/lib/utils.py
@@ -76,18 +76,29 @@ def get_include():
     """
     Return the directory that contains the NumPy \\*.h header files.
 
-    Extension modules that need to compile against NumPy should use this
+    Extension modules that need to compile against NumPy may need to use this
     function to locate the appropriate include directory.
 
     Notes
     -----
-    When using ``distutils``, for example in ``setup.py``::
+    When using ``setuptools``, for example in ``setup.py``::
 
         import numpy as np
         ...
         Extension('extension_name', ...
-                include_dirs=[np.get_include()])
+                  include_dirs=[np.get_include()])
         ...
+
+    Note that a CLI tool ``numpy-config`` was introduced in NumPy 2.0, using
+    that is likely preferred for build systems other than ``setuptools``::
+
+        $ numpy-config --cflags
+        -I/path/to/site-packages/numpy/_core/include
+
+        # Or rely on pkg-config:
+        $ export PKG_CONFIG_PATH=$(numpy-config --pkgconfigdir)
+        $ pkg-config --cflags
+        -I/path/to/site-packages/numpy/_core/include
 
     """
     import numpy
