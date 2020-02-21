--- setup.py.orig	2020-02-08 00:30:40 UTC
+++ setup.py
@@ -44,7 +44,7 @@ class httptools_build_ext(build_ext):
             return
 
         super().initialize_options()
-        self.use_system_http_parser = False
+        self.use_system_http_parser = True
         self.cython_always = False
         self.cython_annotate = None
         self.cython_directives = None
