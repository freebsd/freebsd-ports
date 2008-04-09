--- numpy/distutils/fcompiler/__init__.py.orig	2008-04-06 23:03:15.000000000 +0900
+++ numpy/distutils/fcompiler/__init__.py	2008-04-06 23:08:56.000000000 +0900
@@ -173,7 +173,7 @@
     # gnu95 compiler type when there are F90 sources.
     suggested_f90_compiler = None
 
-    compile_switch = "-c"
+    compile_switch = "-c -fPIC"
     object_switch = "-o "   # Ending space matters! It will be stripped
                             # but if it is missing then object_switch
                             # will be prefixed to object file name by
