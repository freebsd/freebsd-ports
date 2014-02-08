--- /dev/null	2014-02-05 05:15:00.000000000 +0000
+++ build/pkgs/scons/fbsd-patch-src_engine_SCons_compat__scons_subprocess.py	2014-02-05 05:16:45.000000000 +0000
@@ -0,0 +1,31 @@
+--- src/engine/SCons/compat/_scons_subprocess.py.orig	2008-12-21 06:59:59.000000000 +0000
++++ src/engine/SCons/compat/_scons_subprocess.py	2014-02-05 05:11:11.000000000 +0000
+@@ -585,13 +585,19 @@
+     class object:
+         pass
+ 
++import thread
++lock = thread.allocate_lock()
++
+ class Popen(object):
+     def __init__(self, args, bufsize=0, executable=None,
+                  stdin=None, stdout=None, stderr=None,
+                  preexec_fn=None, close_fds=False, shell=False,
+                  cwd=None, env=None, universal_newlines=False,
+                  startupinfo=None, creationflags=0):
+-        """Create new Popen instance."""
++        """Create new Popen instance.
++        Popen is not thread-safe and is therefore protected with a lock.
++        """
++        lock.acquire()
+         _cleanup()
+ 
+         self._child_created = False
+@@ -659,6 +665,7 @@
+                 self.stderr = os.fdopen(errread, 'rU', bufsize)
+             else:
+                 self.stderr = os.fdopen(errread, 'rb', bufsize)
++        lock.release()
+ 
+ 
+     def _translate_newlines(self, data):
