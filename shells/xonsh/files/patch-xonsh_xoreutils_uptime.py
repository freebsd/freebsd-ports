--- xonsh/xoreutils/uptime.py.orig	2018-09-05 14:16:47 UTC
+++ xonsh/xoreutils/uptime.py
@@ -100,13 +100,13 @@ def _uptime_bsd():
         return None
     # Determine how much space we need for the response.
     sz = ctypes.c_uint(0)
-    xp.LIBC.sysctlbyname("kern.boottime", None, ctypes.byref(sz), None, 0)
+    xp.LIBC.sysctlbyname(b"kern.boottime", None, ctypes.byref(sz), None, 0)
     if sz.value != struct.calcsize("@LL"):
         # Unexpected, let's give up.
         return None
     # For real now.
     buf = ctypes.create_string_buffer(sz.value)
-    xp.LIBC.sysctlbyname("kern.boottime", buf, ctypes.byref(sz), None, 0)
+    xp.LIBC.sysctlbyname(b"kern.boottime", buf, ctypes.byref(sz), None, 0)
     sec, usec = struct.unpack_from("@LL", buf.raw)
     # OS X disagrees what that second value is.
     if usec > 1000000:
