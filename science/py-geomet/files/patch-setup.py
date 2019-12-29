--- setup.py.orig	2019-08-20 22:39:12 UTC
+++ setup.py
@@ -61,5 +61,5 @@ setup(
     ],
     zip_safe=False,
     install_requires=['click', 'six'],
-    python_requires=">2.6, !=3.3.*, <3.8",
+    python_requires=">2.6, !=3.3.*, <4",
 )
