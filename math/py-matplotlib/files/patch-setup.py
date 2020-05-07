--- setup.py.orig	2020-03-18 07:54:08 UTC
+++ setup.py
@@ -165,7 +165,6 @@ class develop_with_jquery(DevelopCommand):
 
 
 cmdclass['sdist'] = sdist_with_jquery
-cmdclass['install_lib'] = install_lib_with_jquery
 cmdclass['develop'] = develop_with_jquery
 
 
