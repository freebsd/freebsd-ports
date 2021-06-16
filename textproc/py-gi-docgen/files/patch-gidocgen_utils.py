--- gidocgen/utils.py.orig	2021-04-15 15:10:34 UTC
+++ gidocgen/utils.py
@@ -810,7 +810,7 @@ def find_program(bin_name, path=None):
 
 def default_search_paths():
     if not sys.platform == 'win32':
-        xdg_data_dirs = os.environ.get("XDG_DATA_DIRS", "/usr/share:/usr/local/share").split(":")
+        xdg_data_dirs = os.environ.get("XDG_DATA_DIRS", "/usr/share:%%LOCALBASE%%/share").split(":")
         xdg_data_home = os.environ.get("XDG_DATA_HOME", os.path.expanduser("~/.local/share"))
     else:
         xdg_data_dirs = None
