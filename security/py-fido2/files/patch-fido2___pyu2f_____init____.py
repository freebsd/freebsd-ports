This was part of a pull request that has been merged upstream. Most likely
this patch can be removed on the next release of python-fido2.

See https://github.com/Yubico/python-fido2/pull/64 and
https://github.com/Yubico/python-fido2/commit/19c86d5459931b8a76d1adc76420a8a1e0c0cf2e

--- fido2/_pyu2f/__init__.py.orig	2019-09-10 15:15:37 UTC
+++ fido2/_pyu2f/__init__.py
@@ -47,6 +47,9 @@ def InternalPlatformSwitch(funcname, *args, **kwargs):
   elif sys.platform.startswith('darwin'):
     from . import macos
     clz = macos.MacOsHidDevice
+  elif sys.platform.startswith('freebsd'):
+    from . import freebsd
+    clz = freebsd.FreeBSDHidDevice
 
   if not clz:
     raise Exception('Unsupported platform: ' + sys.platform)
