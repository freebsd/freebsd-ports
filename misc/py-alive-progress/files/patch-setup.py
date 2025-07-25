--- setup.py.orig	2025-07-19 21:36:46 UTC
+++ setup.py
@@ -57,7 +57,6 @@ setup(
              ' stats elapsed time throughput'.split(),
     packages=find_packages(exclude=['tests*']),
     package_data={'alive_progress': ['py.typed']},
-    data_files=[('', ['LICENSE'])],
     python_requires='>=3.9, <4',
-    install_requires=['about_time==4.2.1', 'graphemeu==0.7.2'],
+    install_requires=['about_time>=4.2.1', 'graphemeu>=0.7.2'],
 )
