--- xonsh/xoreutils/uptime.py.orig	2017-02-11 16:24:07 UTC
+++ xonsh/xoreutils/uptime.py
@@ -100,7 +100,7 @@ def _uptime_bsd():
         return None
     # Determine how much space we need for the response.
     sz = ctypes.c_uint(0)
-    xp.LIBC.sysctlbyname('kern.boottime', None, ctypes.byref(sz), None, 0)
+    xp.LIBC.sysctlbyname(b'kern.boottime', None, ctypes.byref(sz), None, 0)
     if sz.value != struct.calcsize('@LL'):
         # Unexpected, let's give up.
         return None
