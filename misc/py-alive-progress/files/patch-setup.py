--- setup.py.orig	2024-10-26 04:20:04 UTC
+++ setup.py
@@ -57,7 +57,6 @@ setup(
              'multi-threaded REPL alive animated visual feedback simple live efficient monitor '
              'stats elapsed time throughput'.split(),
     packages=find_packages(exclude=['tests*']),
-    data_files=[('', ['LICENSE'])],
     python_requires='>=3.9, <4',
     install_requires=['about_time==4.2.1', 'grapheme==0.6.0'],
 )
