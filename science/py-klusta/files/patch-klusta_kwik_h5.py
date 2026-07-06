-- Replace deprecated ndarray.tostring() with ndarray.tobytes() for NumPy 2.0+ compatibility.
-- ndarray.tostring() was removed in NumPy 2.0.
--- klusta/kwik/h5.py.orig	2026-06-27 16:21:19 UTC
+++ klusta/kwik/h5.py
@@ -193,7 +193,7 @@ class File(object):
                 out = attrs[attr_name]
                 if (isinstance(out, (np.ndarray, np.generic)) and
                         out.dtype.kind == 'S'):
-                    out = out.tostring().decode('UTF-8')
+                    out = out.tobytes().decode('UTF-8')
                     out = out.replace('\x00', '')
                 return out
             except (TypeError, IOError):
