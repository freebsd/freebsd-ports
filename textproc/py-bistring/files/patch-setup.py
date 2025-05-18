--- setup.py.orig	2022-03-14 19:32:46 UTC
+++ setup.py
@@ -43,7 +43,6 @@ setup(
     test_suite='tests',
     python_requires='>=3.7',
     setup_requires=[
-        'pytest-runner',
     ],
     install_requires=[
         'pyicu',
