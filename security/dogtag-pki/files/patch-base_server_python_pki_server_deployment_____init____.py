--- base/server/python/pki/server/deployment/__init__.py.orig	2026-07-28 16:37:15 UTC
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
@@ -62,7 +65,7 @@ seobject = None
 from . import pkimessages as log
 
 seobject = None
-if selinux.is_selinux_enabled():
+if selinux is not None and selinux.is_selinux_enabled():
     try:
         import seobject
     except ImportError:
@@ -114,7 +117,12 @@ class PKIDeployer:
         self.hostname = socket.getfqdn()
 
         # Retrieve DNS domainname
-        self.dns_domainname = subprocess.check_output(["dnsdomainname"])
+        try:
+            self.dns_domainname = subprocess.check_output(["dnsdomainname"])
+        except (FileNotFoundError, subprocess.CalledProcessError):
+            fqdn = socket.getfqdn()
+            domain = fqdn.split(".", 1)[1] if "." in fqdn else ""
+            self.dns_domainname = domain.encode("utf-8")
         self.dns_domainname = self.dns_domainname.decode('ascii').rstrip('\n')
 
         if not len(self.dns_domainname):
@@ -6155,7 +6163,8 @@ class PKIDeployer:
         subsystem.update_realm_config(props)
 
     def create_selinux_contexts(self):
-        if not selinux.is_selinux_enabled() or not seobject:
+        if selinux is None or not selinux.is_selinux_enabled() \
+                or not seobject:
             logger.info('SELinux disabled')
             return
 
@@ -6202,7 +6211,8 @@ class PKIDeployer:
 
     def remove_selinux_contexts(self):
 
-        if not selinux.is_selinux_enabled() or not seobject:
+        if selinux is None or not selinux.is_selinux_enabled() \
+                or not seobject:
             logger.info('SELinux disabled')
             return
 
