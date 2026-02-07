--- build_tools/scripts/core_common/modules/html2.py.orig	2025-04-14 10:11:35 UTC
+++ build_tools/scripts/core_common/modules/html2.py
@@ -17,13 +17,13 @@ def clear_module():
 def make():
   old_cur_dir = os.getcwd()
 
-  print("[fetch]: html")
+  print("[patch & build]: html")
 
   base_dir = base.get_script_dir() + "/../../core/Common/3dParty/html"
   
-  os.chdir(base_dir)
-  base.check_module_version("2", clear_module)
-  os.chdir(old_cur_dir)
+#  os.chdir(base_dir)
+#  base.check_module_version("2", clear_module)
+#  os.chdir(old_cur_dir)
 
   base.cmd_in_dir(base_dir, "python", ["fetch.py"])
   return
