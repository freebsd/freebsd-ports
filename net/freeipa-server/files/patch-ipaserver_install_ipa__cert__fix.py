--- ipaserver/install/ipa_cert_fix.py.orig	2026-01-16 09:23:37 UTC
+++ ipaserver/install/ipa_cert_fix.py
@@ -31,6 +31,7 @@ import logging
 import datetime
 from enum import Enum
 import logging
+import os
 import shutil
 
 from ipalib import api
@@ -63,7 +64,9 @@ any other administrative task.
 any other administrative task.
 """
 
-RENEWED_CERT_PATH_TEMPLATE = "/etc/pki/pki-tomcat/certs/{}-renewed.crt"
+RENEWED_CERT_PATH_TEMPLATE = os.path.join(
+    paths.PKI_TOMCAT, "certs", "{}-renewed.crt"
+)
 
 logger = logging.getLogger(__name__)
 
@@ -104,7 +107,7 @@ class IPACertFix(AdminTool):
             return 1
 
         try:
-            ipautil.run(['pki-server', 'cert-fix', '--help'], raiseonerr=True)
+            ipautil.run([paths.PKI_SERVER, 'cert-fix', '--help'], raiseonerr=True)
         except ipautil.CalledProcessError:
             print(
                 "The 'pki-server cert-fix' command is not available; "
@@ -374,7 +377,7 @@ def run_cert_fix(certs, extra_certs):
         % '-'.join(api.env.realm.split('.'))
     )
     cmd = [
-        'pki-server',
+        paths.PKI_SERVER,
         'cert-fix',
         '--ldapi-socket', ldapi_path,
         '--agent-uid', 'ipara',
@@ -388,7 +391,9 @@ def replicate_dogtag_certs(subject_base, ca_subject_dn
 
 def replicate_dogtag_certs(subject_base, ca_subject_dn, certs):
     for certid, _oldcert in certs:
-        cert_path = "/etc/pki/pki-tomcat/certs/{}.crt".format(certid)
+        cert_path = os.path.join(
+            paths.PKI_TOMCAT, "certs", "{}.crt".format(certid)
+        )
         cert = x509.load_certificate_from_file(cert_path)
         print_cert_info("Renewed Dogtag", certid, cert)
         replicate_cert(subject_base, ca_subject_dn, cert)
