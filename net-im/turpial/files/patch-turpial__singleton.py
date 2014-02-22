--- ./turpial/singleton.py.orig	2013-12-19 01:59:58.000000000 +0000
+++ ./turpial/singleton.py	2014-02-22 11:42:16.000000000 +0000
@@ -12,7 +12,7 @@
 
 from libturpial.common.tools import *
 
-if detect_os() == OS_LINUX:
+if detect_os() == OS_LINUX or detect_os() == OS_FREEBSD or detect_os() == OS_DFLY:
     import fcntl
 
 class Singleton:
@@ -21,7 +21,7 @@
         self.log = logging.getLogger('Sys')
         self.filepath = os.path.abspath(os.path.join(tempfile.gettempdir(), pid_name))
 
-        if detect_os() == OS_LINUX:
+        if detect_os() == OS_LINUX or detect_os() == OS_FREEBSD or detect_os() == OS_DFLY:
             self.fd = open(self.filepath, 'w')
             try:
                 fcntl.lockf(self.fd, fcntl.LOCK_EX | fcntl.LOCK_NB)
