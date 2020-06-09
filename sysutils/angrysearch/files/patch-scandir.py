--- scandir.py.orig	2018-07-28 20:12:38 UTC
+++ scandir.py
@@ -428,6 +428,17 @@ elif sys.platform.startswith(('linux', 'darwin')) or '
                 ('d_type', ctypes.c_byte),
                 ('d_name', ctypes.c_char * 256),
             )
+        elif sys.platform.startswith('freebsd') and int(sys.platform[7:]) > 11:
+            _fields_ = (
+                ('d_ino', ctypes.c_uint64),
+                ('d_off', ctypes.c_uint64),
+                ('d_reclen', ctypes.c_ushort),
+                ('d_type', ctypes.c_byte),
+                ('d_pad0', ctypes.c_byte),
+                ('d_namlen', ctypes.c_ushort),
+                ('d_pad1', ctypes.c_ushort),
+                ('d_name', ctypes.c_char * 256),
+            )
         else:
             _fields_ = (
                 ('d_ino', ctypes.c_uint32),  # must be uint32, not ulong
