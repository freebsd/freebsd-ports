--- setup.py.orig	2020-08-21 08:30:55 UTC
+++ setup.py
@@ -34,7 +34,7 @@ setup(
 
     packages=['sequoia'],
 
-    setup_requires=["cffi>=1.0.0", "pytest-runner"],
+    setup_requires=["cffi>=1.0.0"],
     cffi_modules=["sequoia/sequoia_build.py:ffibuilder"],
     install_requires=["cffi>=1.0.0"],
     tests_require=["pytest"],
