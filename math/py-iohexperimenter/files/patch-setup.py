--- setup.py.orig	2024-04-27 13:56:50 UTC
+++ setup.py
@@ -39,11 +39,11 @@ setup(
 
 
 setup(
-    name="IOHexperimenter",
+    name="iohexperimenter",
     version=__version__,
     author="Furong Ye, Diederick Vermetten, and Hao Wang",
     author_email="f.ye@liacs.leidenuniv.nl",
-    packages=find_packages(),
+    packages=find_packages(exclude=['tests*']),
     description="The experimenter for Iterative Optimization Heuristic",
     long_description=long_description,
     long_description_content_type="text/markdown",
