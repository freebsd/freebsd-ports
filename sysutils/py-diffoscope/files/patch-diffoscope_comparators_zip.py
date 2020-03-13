# Non-portable regression caused by 25fee28c/#879011
# https://lists.reproducible-builds.org/pipermail/diffoscope/2020-March/002632.html
# TODO: Upstream

--- diffoscope/comparators/zip.py.orig	2020-03-12 13:23:59 UTC
+++ diffoscope/comparators/zip.py
@@ -38,10 +38,7 @@ from .utils.command import Command
 class Zipinfo(Command):
     @tool_required('zipinfo')
     def cmdline(self):
-        # zipinfo (without -v) puts warning messages (some of which contain
-        # $path) into stdin when stderr is not a tty, see #879011 for details.
-        # to work around it, we run it on /dev/stdin instead, seems to work ok.
-        return ['zipinfo', '/dev/stdin']
+        return ['zipinfo', self.path]
 
     @property
     def returncode(self):
@@ -54,9 +51,6 @@ class Zipinfo(Command):
             returncode = 0
 
         return returncode
-
-    def stdin(self):
-        return open(self.path, 'rb')
 
     def filter(self, line):
         # we don't care about the archive file path
