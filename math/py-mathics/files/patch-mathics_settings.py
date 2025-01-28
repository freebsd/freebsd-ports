--- mathics/settings.py.orig	2025-01-28 08:58:07 UTC
+++ mathics/settings.py
@@ -110,7 +110,7 @@ def ensure_directory(directory: str):
     """
     dir_path = Path(directory)
     if not dir_path.is_dir():
-        os.mkdir(directory)
+        os.makedirs(directory)
 
 
 def get_doctest_latex_data_path(should_be_readable=False, create_parent=False) -> str:
