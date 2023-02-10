--- setup.py.orig	2022-12-22 05:23:53 UTC
+++ setup.py
@@ -55,7 +55,6 @@ setup(
              'multi-threaded REPL alive animated visual feedback simple live efficient monitor '
              'stats elapsed time throughput'.split(),
     packages=find_packages(exclude=['tests*']),
-    data_files=[('', ['LICENSE'])],
     python_requires='>=3.7, <4',
     install_requires=['about_time==4.2.1', 'grapheme==0.6.0'],
 )
