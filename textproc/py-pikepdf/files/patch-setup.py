Relax build requirements as devel/py-setuptools in the Ports tree is still
at release 44.0 due Python 2.7.

--- setup.py.orig	2021-01-27 00:16:08 UTC
+++ setup.py
@@ -88,8 +88,8 @@ if __name__ == '__main__':
             'Pillow >= 6',  # only needed for manipulating images
         ],
         setup_requires=[
-            'setuptools >= 50',
-            'wheel >= 0.35',
+            'setuptools',
+            'wheel',
             'setuptools_scm[toml] >= 4.1',
             'setuptools_scm_git_archive',
             'pybind11 >= 2.6.0, <3',
