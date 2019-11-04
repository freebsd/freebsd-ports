--- installer/dcheck.py.orig	2019-11-03 15:17:23 UTC
+++ installer/dcheck.py
@@ -48,7 +48,11 @@ mod_output = ''
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
@@ -370,7 +374,10 @@ def get_pil_version():
     except ImportError:
         return '-'
     else:
-         return Image.PILLOW_VERSION
+        if hasattr(Image, "__version__"): # required for Pillow >= 6.0.0
+            return Image.__version__
+        else:
+            return Image.PILLOW_VERSION
 
 def get_libpthread_version():
     try:
@@ -378,6 +385,8 @@ def get_libpthread_version():
     except ImportError:
         return '-'
     else:
+        if sys.platform.startswith('freebsd'):
+            return '-'
 #        LIBC = ctypes.CDLL(ctypes.util.find_library('c'), use_errno=True)
         LIBC = ctypes.CDLL(ctypes.util.find_library('c'),ctypes.DEFAULT_MODE,None, True)
         LIBC.gnu_get_libc_version.restype = ctypes.c_char_p
