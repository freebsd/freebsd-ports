--- base/server/python/pki/server/deployment/scriptlets/selinux_setup.py.orig	2026-07-04 19:39:16 UTC
+++ base/server/python/pki/server/deployment/scriptlets/selinux_setup.py
@@ -20,7 +20,10 @@ import logging

 from __future__ import absolute_import
 import logging
-import selinux
+try:
+    import selinux
+except ImportError:
+    selinux = None
 import sys
 import time

@@ -30,7 +33,7 @@ seobject = None
 from .. import pkiscriptlet

 seobject = None
-if selinux.is_selinux_enabled():
+if selinux is not None and selinux.is_selinux_enabled():
     try:
         import seobject
     except ImportError:
@@ -51,7 +54,7 @@ class PkiScriptlet(pkiscriptlet.AbstractBasePkiScriptl
             logger.info('Skipping SELinux setup')
             return

-        if not selinux.is_selinux_enabled() or seobject is None:
+        if selinux is None or not selinux.is_selinux_enabled() or seobject is None:
             logger.info('SELinux disabled')
             return

@@ -96,7 +99,7 @@ class PkiScriptlet(pkiscriptlet.AbstractBasePkiScriptl

         instance = self.instance

-        if not bool(selinux.is_selinux_enabled()):
+        if selinux is None or not selinux.is_selinux_enabled():
             logger.info('SELinux disabled')
             return
