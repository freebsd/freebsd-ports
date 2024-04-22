--- setup.py.orig	2024-03-17 11:40:14 UTC
+++ setup.py
@@ -20,7 +20,7 @@ setuptools.setup(
         'pycairo',
     ],
     packages=setuptools.find_packages(exclude=('tests', )),
-    data_files = [('man/man1', ['doc/mat2.1'])],
+    data_files = [('share/man/man1', ['doc/mat2.1'])],
     classifiers=[
         "Development Status :: 3 - Alpha",
         "Environment :: Console",
