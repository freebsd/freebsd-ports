-- Fix path calculation in resource_path when PyInstaller is not used.
-- Falling back to os.path.dirname(os.path.abspath(__file__)) ensures resource files (like pyobd.ico) are correctly found next to the script in site-packages.
--
--- pyobd.py.orig	2026-06-19 19:04:49 UTC
+++ pyobd.py
@@ -127,7 +127,7 @@ def resource_path(relative_path):
         # PyInstaller creates a temp folder and stores path in _MEIPASS
         base_path = sys._MEIPASS
     except Exception:
-        base_path = os.path.abspath(".")
+        base_path = os.path.dirname(os.path.abspath(__file__))
 
     return os.path.join(base_path, relative_path)
 
