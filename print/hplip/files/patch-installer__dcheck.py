--- ./installer/dcheck.py.orig	2012-11-20 09:51:37.000000000 +0000
+++ ./installer/dcheck.py	2013-01-22 14:25:58.685224662 +0000
@@ -44,7 +44,11 @@
 def update_ld_output():
     # For library checks
     global ld_output
-    status, ld_output = utils.run('%s -p' % os.path.join(utils.which('ldconfig'), 'ldconfig'), log_output=False)
+    if sys.platform.startswith('freebsd'):
+        ld_cmd = '%s -r'
+    else: # linux
+        ld_cmd = '%s -p'
+    status, ld_output = utils.run(ld_cmd % os.path.join(utils.which('ldconfig'), 'ldconfig'), log_output=False)
 
     if status != 0:
         log.debug("ldconfig failed.")
@@ -373,6 +377,8 @@
     except ImportError:
         return '-'
     else:
+        if sys.platform.startswith('freebsd'):
+            return '-'
         LIBC = ctypes.CDLL(ctypes.util.find_library('c'), use_errno=True)
         LIBC.gnu_get_libc_version.restype = ctypes.c_char_p
         return LIBC.gnu_get_libc_version()
