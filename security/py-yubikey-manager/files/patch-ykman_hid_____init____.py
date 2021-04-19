--- ykman/hid/__init__.py.orig	2021-04-12 07:23:08 UTC
+++ ykman/hid/__init__.py
@@ -42,12 +42,15 @@ elif sys.platform.startswith("win32"):
     from . import windows as backend
 elif sys.platform.startswith("darwin"):
     from . import macos as backend
+elif sys.platform.startswith("freebsd"):
+    backend = None
 else:
     raise Exception("Unsupported platform")
 
-
-list_otp_devices: Callable[[], List[OtpYubiKeyDevice]] = backend.list_devices
-
+if backend is not None:
+    list_otp_devices: Callable[[], List[OtpYubiKeyDevice]] = backend.list_devices
+else:
+    list_otp_devices: Callable[[], List[OtpYubiKeyDevice]] = lambda: []
 
 class CtapYubiKeyDevice(YkmanDevice):
     """YubiKey FIDO USB HID device"""
