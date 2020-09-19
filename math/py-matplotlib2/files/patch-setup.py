--- setup.py.orig	2019-02-26 00:18:32 UTC
+++ setup.py
@@ -189,7 +189,6 @@ class develop_with_jquery(DevelopCommand
 
 
 cmdclass['sdist'] = sdist_with_jquery
-cmdclass['install_lib'] = install_lib_with_jquery
 cmdclass['develop'] = develop_with_jquery
 
 
