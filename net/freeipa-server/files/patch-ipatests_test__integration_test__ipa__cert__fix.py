--- ipatests/test_integration/test_ipa_cert_fix.py.orig	2026-01-16 09:23:34 UTC
+++ ipatests/test_integration/test_ipa_cert_fix.py
@@ -189,8 +189,10 @@ class TestIpaCertFix(IntegrationTest):
         result = self.master.run_command(['ipa-cert-fix', '-v'],
                                          stdin_text='yes\n',
                                          raiseonerr=False)
-        msg = ("No such file or directory: "
-               "'/etc/pki/pki-tomcat/certs/sslserver.crt'")
+        msg = (
+            "No such file or directory: "
+            "'{}/certs/sslserver.crt'".format(paths.PKI_TOMCAT)
+        )
         assert msg not in result.stderr_text
 
         # Because of BZ 1897120, pki-cert-fix fails on pki-core 10.10.0
