Fix ioctl(2) definitions to match <sys/ioccom.h> and <dev/hid/hidraw.h>

--- hidtools/hidraw.py.orig	2024-07-29 08:55:11 UTC
+++ hidtools/hidraw.py
@@ -39,13 +39,14 @@ def _ioctl(fd, EVIOC, code, return_type, buf=None):
 
 
 # extracted from <asm-generic/ioctl.h>
-_IOC_WRITE: Final = 1
+_IOC_VOID: Final = 1
 _IOC_READ: Final = 2
+_IOC_WRITE: Final = 4
 
 _IOC_NRBITS: Final = 8
 _IOC_TYPEBITS: Final = 8
-_IOC_SIZEBITS: Final = 14
-_IOC_DIRBITS: Final = 2
+_IOC_SIZEBITS: Final = 13
+_IOC_DIRBITS: Final = 3
 
 _IOC_NRSHIFT: Final = 0
 _IOC_TYPESHIFT: Final = _IOC_NRSHIFT + _IOC_NRBITS
@@ -79,7 +80,7 @@ def _IOC_HIDIOCGRDESCSIZE(none, len):
 
 # define HIDIOCGRDESCSIZE	_IOR('H', 0x01, int)
 def _IOC_HIDIOCGRDESCSIZE(none, len):
-    return _IOR("H", 0x01, len)
+    return _IOR("U", 30, len)
 
 
 def _HIDIOCGRDESCSIZE(fd):
@@ -90,7 +91,7 @@ def _IOC_HIDIOCGRDESC(none, len):
 
 # define HIDIOCGRDESC		_IOR('H', 0x02, struct hidraw_report_descriptor)
 def _IOC_HIDIOCGRDESC(none, len):
-    return _IOR("H", 0x02, len)
+    return _IOC(_IOC_VOID, "U", 31, 0)
 
 
 def _HIDIOCGRDESC(fd, size):
@@ -106,7 +107,7 @@ def _IOC_HIDIOCGRAWINFO(none, len):
 
 # define HIDIOCGRAWINFO		_IOR('H', 0x03, struct hidraw_devinfo)
 def _IOC_HIDIOCGRAWINFO(none, len):
-    return _IOR("H", 0x03, len)
+    return _IOR("U", 32, len)
 
 
 def _HIDIOCGRAWINFO(fd):
@@ -117,7 +118,7 @@ def _IOC_HIDIOCGRAWNAME(none, len):
 
 # define HIDIOCGRAWNAME(len)     _IOC(_IOC_READ, 'H', 0x04, len)
 def _IOC_HIDIOCGRAWNAME(none, len):
-    return _IOC(_IOC_READ, "H", 0x04, len)
+    return _IOC(_IOC_READ, "U", 33, len)
 
 
 def _HIDIOCGRAWNAME(fd):
@@ -130,7 +131,7 @@ def _IOC_HIDIOCGFEATURE(none, len):
 
 # define HIDIOCGFEATURE(len) _IOC(_IOC_WRITE|_IOC_READ, 'H', 0x07, len)
 def _IOC_HIDIOCGFEATURE(none, len):
-    return _IOC(_IOC_WRITE | _IOC_READ, "H", 0x07, len)
+    return _IOC(_IOC_WRITE | _IOC_READ, "U", 36, len)
 
 
 def _HIDIOCGFEATURE(fd, report_id, rsize):
@@ -145,7 +146,7 @@ def _IOC_HIDIOCSFEATURE(none, len):
 
 # define HIDIOCSFEATURE(len) _IOC(_IOC_WRITE|_IOC_READ, 'H', 0x06, len)
 def _IOC_HIDIOCSFEATURE(none, len):
-    return _IOC(_IOC_WRITE | _IOC_READ, "H", 0x06, len)
+    return _IOC(_IOC_WRITE, "U", 35, len)
 
 
 def _HIDIOCSFEATURE(fd, data):
