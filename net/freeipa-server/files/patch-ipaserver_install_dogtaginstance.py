--- ipaserver/install/dogtaginstance.py.orig	2026-01-16 09:23:37 UTC
+++ ipaserver/install/dogtaginstance.py
@@ -205,7 +205,7 @@ class DogtagInstance(service.Service):
         """
         try:
             result = ipautil.run(
-                ['pki-server', 'subsystem-show', self.subsystem.lower()],
+                [paths.PKI_SERVER, 'subsystem-show', self.subsystem.lower()],
                 capture_output=True)
             # parse the command output
             return 'Enabled: ' in result.output
@@ -339,7 +339,7 @@ class DogtagInstance(service.Service):
                 pki.util.Version("11.0.0") <= pki_version
                 < pki.util.Version("11.6.0")
             ):
-                args = ['pki-server', 'acme-remove']
+                args = [paths.PKI_SERVER, 'acme-remove']
             else:
                 # fall through for PKI >= 11.6.0
                 pass
