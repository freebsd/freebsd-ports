--- numpy/distutils/fcompiler/__init__.py.orig	2019-01-31 02:31:08 UTC
+++ numpy/distutils/fcompiler/__init__.py
@@ -177,7 +177,7 @@ class FCompiler(CCompiler):
     # gnu95 compiler type when there are F90 sources.
     suggested_f90_compiler = None
 
-    compile_switch = "-c"
+    compile_switch = "-fPIC"
     object_switch = "-o "   # Ending space matters! It will be stripped
                             # but if it is missing then object_switch
                             # will be prefixed to object file name by
