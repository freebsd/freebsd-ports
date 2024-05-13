--- setup.py.orig	2024-02-02 16:03:42 UTC
+++ setup.py
@@ -39,7 +39,7 @@ def run_setup(with_binary):
 
 def run_setup(with_binary):
     setup(
-        name="MarkupSafe",
+        name="markupsafe",
         cmdclass={"build_ext": ve_build_ext},
         ext_modules=ext_modules if with_binary else [],
     )
