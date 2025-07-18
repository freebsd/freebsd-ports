--- setup.py.orig	2025-07-18 17:28:03 UTC
+++ setup.py
@@ -72,7 +72,6 @@ setup(
     # your project is installed. For an analysis of "install_requires" vs pip's
     # requirements files see:
     # https://packaging.python.org/en/latest/requirements.html
-    setup_requires=['pytest-runner',],
     tests_require=['pytest',],
 
     install_requires=['pyparsing'],
