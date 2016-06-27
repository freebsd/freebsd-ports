--- setup.py.orig	2015-11-10 15:05:16 UTC
+++ setup.py
@@ -42,7 +42,7 @@ setup(
     entry_points={
         'gui_scripts': ['pivman=pivman.__main__:main']
     },
-    install_requires=['PySide', 'pycrypto'],
+    install_requires=['pycrypto'],
     yc_requires=['ctypes', 'qt'],
     test_suite='nose.collector',
     tests_require=[''],
