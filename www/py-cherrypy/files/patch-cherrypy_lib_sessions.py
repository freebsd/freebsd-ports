Remove contextlib2 and use contextlib from the standard library.

* Contextlib has been in the Python standard library since Python 3.2.
* Contextlib2 is a backport to Python 2 (and is supported through Python 3.7).

Obtained from: https://github.com/cherrypy/cherrypy/commit/2fc78dc9af3e

--- cherrypy/lib/sessions.py.orig	2021-04-22 13:06:39 UTC
+++ cherrypy/lib/sessions.py
@@ -109,7 +109,7 @@ import binascii

 import six
 from six.moves import cPickle as pickle
-import contextlib2
+import contextlib

 import zc.lockfile

@@ -572,7 +572,7 @@ class FileSession(Session):
     def release_lock(self, path=None):
         """Release the lock on the currently-loaded session data."""
         self.lock.close()
-        with contextlib2.suppress(FileNotFoundError):
+        with contextlib.suppress(FileNotFoundError):
             os.remove(self.lock._path)
         self.locked = False

