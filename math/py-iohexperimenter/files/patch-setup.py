--- setup.py.orig	2021-01-29 16:13:26 UTC
+++ setup.py
@@ -43,7 +43,7 @@ setup(
     version=__version__,
     author="Furong Ye, Diederick Vermetten, and Hao Wang",
     author_email="f.ye@liacs.leidenuniv.nl",
-    packages=find_packages(),
+    packages=find_packages(exclude=['tests*']),
     description="The experimenter for Iterative Optimization Heuristic",
     long_description=long_description,
     long_description_content_type="text/markdown",
