--- installer/dcheck.py.orig	2013-02-21 18:40:18.368768559 -0800
+++ installer/dcheck.py	2013-02-21 18:43:03.116783408 -0800
@@ -46,7 +46,11 @@
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
@@ -360,6 +364,8 @@
     except ImportError:
         return '-'
     else:
+        if sys.platform.startswith('freebsd'):
+            return '-'
 #        LIBC = ctypes.CDLL(ctypes.util.find_library('c'), use_errno=True)
         LIBC = ctypes.CDLL(ctypes.util.find_library('c'),ctypes.DEFAULT_MODE,None, True)
         LIBC.gnu_get_libc_version.restype = ctypes.c_char_p
