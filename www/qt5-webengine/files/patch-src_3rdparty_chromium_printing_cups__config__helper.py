--- src/3rdparty/chromium/printing/cups_config_helper.py.orig	2017-01-26 00:49:17 UTC
+++ src/3rdparty/chromium/printing/cups_config_helper.py
@@ -65,7 +65,7 @@ def main():
   mode = sys.argv[1]
   if len(sys.argv) > 2 and sys.argv[2]:
     sysroot = sys.argv[2]
-    cups_config = os.path.join(sysroot, 'usr', 'bin', 'cups-config')
+    cups_config = os.path.join(sysroot, 'bin', 'cups-config')
     if not os.path.exists(cups_config):
       print 'cups-config not found: %s' % cups_config
       return 1
