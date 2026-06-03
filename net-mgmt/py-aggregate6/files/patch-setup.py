--- setup.py.orig	2026-04-03 21:50:56 UTC
+++ setup.py
@@ -85,6 +85,6 @@ setup(
     packages=find_packages(exclude=['tests', 'tests.*']),
     entry_points={'console_scripts':
                   ['aggregate6 = aggregate6.aggregate6:main']},
-    data_files=[('man/man7', ['aggregate6.7'])],
+    data_files=[('share/man/man7', ['aggregate6.7'])],
     test_suite='nose.collector'
 )
