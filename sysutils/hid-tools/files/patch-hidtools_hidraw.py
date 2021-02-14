Fix ioctl(2) definitions to match <sys/ioccom.h> and <dev/hid/hidraw.h>

--- hidtools/hidraw.py.orig	2019-03-29 01:29:29 UTC
+++ hidtools/hidraw.py
@@ -36,13 +36,14 @@ def _ioctl(fd, EVIOC, code, return_type, buf=None):
 
 
 # extracted from <asm-generic/ioctl.h>
-_IOC_WRITE = 1
+_IOC_VOID = 1
 _IOC_READ = 2
+_IOC_WRITE = 4
 
 _IOC_NRBITS = 8
 _IOC_TYPEBITS = 8
-_IOC_SIZEBITS = 14
-_IOC_DIRBITS = 2
+_IOC_SIZEBITS = 13
+_IOC_DIRBITS = 3
 
 _IOC_NRSHIFT = 0
 _IOC_TYPESHIFT = _IOC_NRSHIFT + _IOC_NRBITS
@@ -74,7 +75,7 @@ def _IOW(type, nr, size):
 
 # define HIDIOCGRDESCSIZE	_IOR('H', 0x01, int)
 def _IOC_HIDIOCGRDESCSIZE(none, len):
-    return _IOR('H', 0x01, len)
+    return _IOR('U', 30, len)
 
 
 def _HIDIOCGRDESCSIZE(fd):
@@ -85,7 +86,7 @@ def _HIDIOCGRDESCSIZE(fd):
 
 # define HIDIOCGRDESC		_IOR('H', 0x02, struct hidraw_report_descriptor)
 def _IOC_HIDIOCGRDESC(none, len):
-    return _IOR('H', 0x02, len)
+    return _IOC(_IOC_VOID, 'U', 31, 0)
 
 
 def _HIDIOCGRDESC(fd, size):
@@ -102,7 +103,7 @@ def _HIDIOCGRDESC(fd, size):
 
 # define HIDIOCGRAWINFO		_IOR('H', 0x03, struct hidraw_devinfo)
 def _IOC_HIDIOCGRAWINFO(none, len):
-    return _IOR('H', 0x03, len)
+    return _IOR('U', 32, len)
 
 
 def _HIDIOCGRAWINFO(fd):
@@ -113,7 +114,7 @@ def _HIDIOCGRAWINFO(fd):
 
 # define HIDIOCGRAWNAME(len)     _IOC(_IOC_READ, 'H', 0x04, len)
 def _IOC_HIDIOCGRAWNAME(none, len):
-    return _IOC(_IOC_READ, 'H', 0x04, len)
+    return _IOC(_IOC_READ, 'U', 33, len)
 
 
 def _HIDIOCGRAWNAME(fd):
