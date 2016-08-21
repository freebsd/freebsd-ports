--- setup.py.orig	2016-08-16 07:51:31 UTC
+++ setup.py
@@ -42,7 +42,6 @@ setup(
     entry_points={
         'gui_scripts': ['pivman=pivman.__main__:main']
     },
-    install_requires=['PySide'],
     yc_requires=['ctypes', 'qt'],
     test_suite='test',
     tests_require=[''],
