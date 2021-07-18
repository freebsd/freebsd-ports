--- setup.py.orig	2021-04-23 20:30:51 UTC
+++ setup.py
@@ -48,7 +48,7 @@ class httptools_build_ext(build_ext):
 
         super().initialize_options()
         self.use_system_llhttp = False
-        self.use_system_http_parser = False
+        self.use_system_http_parser = True
         self.cython_always = False
         self.cython_annotate = None
         self.cython_directives = None
