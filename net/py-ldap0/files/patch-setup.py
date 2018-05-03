--- setup.py.orig	2018-02-06 13:04:47 UTC
+++ setup.py
@@ -22,7 +22,7 @@ class OpenLDAP2BuildConfig:
 
     def __init__(self, meta_defines):
         self.library_dirs = []
-        self.include_dirs = []
+        self.include_dirs = [os.environ['INCLUDES']]
         self.extra_compile_args = []
         self.extra_link_args = []
         self.extra_objects = []
