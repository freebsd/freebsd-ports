--- setup.py.orig	2021-01-17 19:26:34 UTC
+++ setup.py
@@ -92,7 +92,7 @@ setup(
     install_requires=install_requires,
     extras_require=extras_require,
     python_requires='>=2.7,!=3.0.*,!=3.1.*,!=3.2.*',
-    packages=find_packages(exclude=['docs']),
+    packages=find_packages(exclude=['docs', 'tests*']),
     include_package_data=True,
     cmdclass={'sdist': Sdist},
     entry_points={
