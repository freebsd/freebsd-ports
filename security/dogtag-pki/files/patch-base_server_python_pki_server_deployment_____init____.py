--- base/server/python/pki/server/deployment/__init__.py.orig	2026-07-04 19:39:15 UTC
+++ base/server/python/pki/server/deployment/__init__.py
@@ -28,7 +28,10 @@ import re
 import os
 import pathlib
 import re
-import selinux
+try:
+    import selinux
+except ImportError:
+    selinux = None
 import shutil
 import socket
 import struct
@@ -69,7 +72,7 @@ seobject = None
 from . import pkimessages as log

 seobject = None
-if selinux.is_selinux_enabled():
+if selinux is not None and selinux.is_selinux_enabled():
     try:
         import seobject
     except ImportError:
