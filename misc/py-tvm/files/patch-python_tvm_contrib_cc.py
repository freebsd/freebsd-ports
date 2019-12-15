--- python/tvm/contrib/cc.py.orig	2019-11-27 03:24:12 UTC
+++ python/tvm/contrib/cc.py
@@ -27,7 +27,7 @@ from .util import tempdir
 def create_shared(output,
                   objects,
                   options=None,
-                  cc="g++"):
+                  cc="c++"):
     """Create shared library.
 
     Parameters
@@ -44,7 +44,7 @@ def create_shared(output,
     cc : Optional[str]
         The compiler command.
     """
-    if sys.platform == "darwin" or sys.platform.startswith("linux"):
+    if sys.platform == "darwin" or sys.platform.startswith("linux") or sys.platform.startswith("freebsd"):
         _linux_compile(output, objects, options, cc)
     elif sys.platform == "win32":
         _windows_shared(output, objects, options)
@@ -56,7 +56,7 @@ def create_shared(output,
 create_shared.output_format = "so" if sys.platform != "win32" else "dll"
 
 
-def build_create_shared_func(options=None, compile_cmd="g++"):
+def build_create_shared_func(options=None, compile_cmd="c++"):
     """Build create_shared function with particular default options and compile_cmd.
 
     Parameters
@@ -108,7 +108,7 @@ def cross_compiler(compile_func, base_options=None, ou
     return _fcompile
 
 
-def _linux_compile(output, objects, options, compile_cmd="g++"):
+def _linux_compile(output, objects, options, compile_cmd="c++"):
     cmd = [compile_cmd]
     if output.endswith(".so") or output.endswith(".dylib"):
         cmd += ["-shared", "-fPIC"]
