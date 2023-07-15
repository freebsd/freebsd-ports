--- lib/googlecloudsdk/core/util/platforms.py.orig	2023-07-15 12:32:47 UTC
+++ lib/googlecloudsdk/core/util/platforms.py
@@ -156,8 +156,9 @@ class OperatingSystem(object):
   MACOSX = _OS('MACOSX', 'Mac OS X', 'darwin')
   LINUX = _OS('LINUX', 'Linux', 'linux')
   CYGWIN = _OS('CYGWIN', 'Cygwin', 'cygwin')
+  FREEBSD = _OS('FREEBSD', 'FreeBSD', 'freebsd')
   MSYS = _OS('MSYS', 'Msys', 'msys')
-  _ALL = [WINDOWS, MACOSX, LINUX, CYGWIN, MSYS]
+  _ALL = [WINDOWS, MACOSX, LINUX, CYGWIN, FREEBSD, MSYS]
 
   @staticmethod
   def AllValues():
@@ -210,6 +211,8 @@ class OperatingSystem(object):
       return OperatingSystem.MACOSX
     elif 'cygwin' in sys.platform:
       return OperatingSystem.CYGWIN
+    elif 'freebsd' in sys.platform:
+      return OperatingSystem.FREEBSD
     return None
 
   @staticmethod
