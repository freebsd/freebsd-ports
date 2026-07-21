--- base/server/python/pki/server/deployment/scriptlets/configuration.py.orig	2026-07-12 17:21:04 UTC
+++ base/server/python/pki/server/deployment/scriptlets/configuration.py
@@ -20,12 +20,14 @@ import logging
 
 from __future__ import absolute_import
 import logging
+import os
 
 # PKI Deployment Imports
 from .. import pkiconfig as config
 from .. import pkiscriptlet
 
 import pki.nssdb
+import pki.server
 
 logger = logging.getLogger(__name__)
 
@@ -90,7 +92,11 @@ class PkiScriptlet(pkiscriptlet.AbstractBasePkiScriptl
 
             if not clone and subsystem.type == 'CA':
                 subsystem.import_profiles(
-                    input_folder='/usr/share/pki/ca/profiles/ca')
+                    input_folder=os.path.join(
+                        pki.server.PKIServer.SHARE_DIR,
+                        'ca',
+                        'profiles',
+                        'ca'))
 
         subsystem.load()
 
