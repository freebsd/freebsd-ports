--- setup.py.orig	2020-03-28 11:06:35 UTC
+++ setup.py
@@ -55,5 +55,5 @@ setup(
         "Programming Language :: Python :: 3.6",
         "Programming Language :: Python :: 3.7",
     ],
-    packages=find_packages(),
+    packages=find_packages(exclude=['tests*']),
 )
