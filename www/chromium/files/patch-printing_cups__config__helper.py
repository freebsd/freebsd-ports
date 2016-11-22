--- printing/cups_config_helper.py.orig	2016-08-03 22:02:22.000000000 +0300
+++ printing/cups_config_helper.py	2016-09-02 22:48:48.706284000 +0300
@@ -65,7 +65,7 @@
   mode = sys.argv[1]
   if len(sys.argv) > 2 and sys.argv[2]:
     sysroot = sys.argv[2]
-    cups_config = os.path.join(sysroot, 'usr', 'bin', 'cups-config')
+    cups_config = os.path.join(sysroot, 'bin', 'cups-config')
     if not os.path.exists(cups_config):
       print 'cups-config not found: %s' % cups_config
       return 1
