--- setup.py.orig	2015-01-24 14:55:05.507732433 -0700
+++ setup.py	2015-01-24 14:59:07.595716022 -0700
@@ -621,8 +621,8 @@
     def _property_data_files(self):
         # Data files common to all scenarios
         data_files = [
-            ('share/man/man1', ['doc/man/salt-call.1']),
-            ('share/man/man7', ['doc/man/salt.7'])
+            ('man/man1', ['doc/man/salt-call.1']),
+            ('man/man7', ['doc/man/salt.7'])
         ]
         if self.ssh_packaging or PACKAGED_FOR_SALT_SSH:
             data_files[0][1].append('doc/man/salt-ssh.1')
