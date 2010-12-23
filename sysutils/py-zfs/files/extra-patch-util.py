--- util.py.orig	2010-12-23 09:07:09.188744296 +0100
+++ util.py	2010-12-23 09:10:16.315849339 +0100
@@ -28,7 +28,6 @@
 import gettext
 import errno
 import os
-import solaris.misc
 # Note: this module (zfs.util) should not import zfs.ioctl, because that
 # would introduce a circular dependency
 
@@ -37,11 +36,8 @@
 
 dev = open("/dev/zfs", "w")
 
-try:
-	_ = gettext.translation("SUNW_OST_OSLIB", "/usr/lib/locale",
-	    fallback=True).gettext
-except:
-	_ = solaris.misc.gettext
+_ = gettext.translation("SUNW_OST_OSLIB", "/usr/lib/locale",
+    fallback=True).gettext
 
 def default_repr(self):
 	"""A simple __repr__ function."""
