Relax version requirement of devel/py-future

--- setup.py.orig	2021-11-04 18:14:51 UTC
+++ setup.py
@@ -19,5 +19,5 @@ setup(
     ],
     zip_safe=False,
     packages=find_packages(),
-    install_requires=['pyrad >= 1.2', 'future==0.16.0'],
+    install_requires=['pyrad >= 1.2', 'future>=0.16.0'],
 )
