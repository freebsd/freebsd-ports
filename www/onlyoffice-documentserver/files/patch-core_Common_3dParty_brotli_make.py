--- core/Common/3dParty/brotli/make.py.orig	2025-08-02 18:33:34 UTC
+++ core/Common/3dParty/brotli/make.py
@@ -10,7 +10,7 @@ def clear_module():
     base.delete_dir_with_access_error("brotli")
   return
 
-base.check_module_version("1", clear_module)
+#base.check_module_version("1", clear_module)
 
 # fetch harfbuzz
 if not base.is_dir("brotli"):
