--- setup.py.orig	2016-11-22 16:50:54 UTC
+++ setup.py
@@ -988,8 +988,8 @@ class SaltDistribution(distutils.dist.Di
     def _property_data_files(self):
         # Data files common to all scenarios
         data_files = [
-            ('share/man/man1', ['doc/man/salt-call.1', 'doc/man/salt-run.1']),
-            ('share/man/man7', ['doc/man/salt.7'])
+            ('man/man1', ['doc/man/salt-call.1', 'doc/man/salt-run.1']),
+            ('man/man7', ['doc/man/salt.7'])
         ]
         if self.ssh_packaging or PACKAGED_FOR_SALT_SSH:
             data_files[0][1].append('doc/man/salt-ssh.1')
