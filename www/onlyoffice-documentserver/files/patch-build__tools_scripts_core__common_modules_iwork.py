--- build_tools/scripts/core_common/modules/iwork.py.orig	2025-08-05 15:06:08 UTC
+++ build_tools/scripts/core_common/modules/iwork.py
@@ -30,9 +30,9 @@ def make(use_gperf = True):
   if use_gperf:
     cmd_args.append("--gperf")
 
-  base.cmd_in_dir(base_dir, "python", cmd_args)
+#  base.cmd_in_dir(base_dir, "python", cmd_args)
   return
 
 if __name__ == '__main__':
   # manual compile
-  make(False)
\ No newline at end of file
+  make(False)
