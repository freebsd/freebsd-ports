--- ./usr/share/google/google_daemon/accounts_manager.py.orig	2014-08-10 19:54:20.429932607 +0000
+++ ./usr/share/google/google_daemon/accounts_manager.py	2014-08-10 19:55:06.794964428 +0000
@@ -1,3 +1,4 @@
+#!%%PYTHON_CMD%%
 # Copyright 2013 Google Inc. All Rights Reserved.
 #
 # Licensed under the Apache License, Version 2.0 (the "License");
@@ -20,7 +21,7 @@
 import pwd
 import time
 
-LOCKFILE = '/var/lock/manage-accounts.lock'
+LOCKFILE = '/var/run/manage-accounts.lock'
 
 
 class AccountsManager(object):
@@ -95,8 +96,8 @@
   def RegenerateKeysAndUpdateAccounts(self):
     """Regenerate the keys and update accounts as needed."""
     logging.debug('RegenerateKeysAndUpdateAccounts')
-    if self.system.IsExecutable('/usr/share/google/first-boot'):
-      self.system.RunCommand('/usr/share/google/first-boot')
+    if self.system.IsExecutable('%%PREFIX%%/share/google/first-boot'):
+      self.system.RunCommand('%%PREFIX%%/share/google/first-boot')
 
     self.lock_file.RunExclusively(self.lock_fname, self.UpdateAccounts)
 
