--- setup.py.orig	2023-06-29 15:35:53 UTC
+++ setup.py
@@ -63,7 +63,6 @@ setup(
     include_dirs=[
         numpy.get_include(),
         dimod.get_include(),
-        'extern/spdlog/include/',
         ],
     install_requires=[
         'numpy>=1.17.3,<2.0.0',  # this is the oldest supported NumPy on Python 3.8
