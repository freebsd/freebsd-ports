Remove contextlib2 and use contextlib from the standard library.

* Contextlib has been in the Python standard library since Python 3.2.
* Contextlib2 is a backport to Python 2 (and is supported through Python 3.7).

Obtained from: https://github.com/cherrypy/cherrypy/commit/2fc78dc9af3e

--- setup.py.orig	2021-04-22 13:05:31 UTC
+++ setup.py
@@ -66,7 +66,6 @@ params = dict(
         'portend>=2.1.1',
         'more_itertools',
         'zc.lockfile',
-        'contextlib2',
     ],
     extras_require={
         'docs': [
