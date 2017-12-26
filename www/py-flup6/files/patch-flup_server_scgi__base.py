--- flup/server/scgi_base.py.orig	2017-12-16 07:40:10 UTC
+++ flup/server/scgi_base.py
@@ -32,7 +32,7 @@ import logging
 import socket
 import select
 import errno
-import cStringIO as StringIO
+import io as StringIO
 import signal
 import datetime
 import os
@@ -40,7 +40,11 @@ import warnings
 
 # Threads are required. If you want a non-threaded (forking) version, look at
 # SWAP <http://www.idyll.org/~t/www-tools/wsgi/>.
-import thread
+try:
+    import thread
+except:
+    import _thread as thread
+
 import threading
 
 __all__ = ['BaseSCGIServer']
