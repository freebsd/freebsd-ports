--- printing/cups_config_helper.py.orig	2020-11-13 06:36:46 UTC
+++ printing/cups_config_helper.py
@@ -67,7 +67,7 @@ def main():
   mode = sys.argv[1]
   if len(sys.argv) > 2 and sys.argv[2]:
     sysroot = sys.argv[2]
-    cups_config = os.path.join(sysroot, 'usr', 'bin', 'cups-config')
+    cups_config = os.path.join(sysroot, 'bin', 'cups-config')
     if not os.path.exists(cups_config):
       print('cups-config not found: %s' % cups_config)
       return 1
