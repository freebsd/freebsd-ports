--- base/server/python/pki/server/deployment/__init__.py.orig	2025-08-05 19:20:05 UTC
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
@@ -123,7 +126,12 @@ class PKIDeployer:
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
