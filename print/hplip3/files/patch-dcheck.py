--- installer/dcheck.py.orig	2009-08-05 09:37:17.000000000 +1200
+++ installer/dcheck.py	2009-11-27 18:53:56.000000000 +1300
@@ -46,7 +46,7 @@
 def update_ld_output():
     # For library checks
     global ld_output
-    status, ld_output = utils.run('%s -p' % os.path.join(utils.which('ldconfig'), 'ldconfig'), log_output=False)
+    status, ld_output = utils.run('%s -r' % os.path.join(utils.which('ldconfig'), 'ldconfig'), log_output=False)
 
     if status != 0:
         log.debug("ldconfig failed.")
