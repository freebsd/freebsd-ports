--- setup.py.orig	2021-04-26 15:51:55 UTC
+++ setup.py
@@ -15,7 +15,7 @@ CFLAGS = ['-O2']
 
 ROOT = pathlib.Path(__file__).parent
 
-CYTHON_DEPENDENCY = 'Cython==0.29.22'
+CYTHON_DEPENDENCY = 'Cython>=0.29.21'
 
 
 class httptools_build_ext(build_ext):
@@ -44,7 +44,7 @@ class httptools_build_ext(build_ext):
             return
 
         super().initialize_options()
-        self.use_system_http_parser = False
+        self.use_system_http_parser = True
         self.cython_always = False
         self.cython_annotate = None
         self.cython_directives = None
