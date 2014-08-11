--- ./usr/share/google/google_daemon/accounts.py.orig	2014-08-10 19:54:08.843933565 +0000
+++ ./usr/share/google/google_daemon/accounts.py	2014-08-10 19:54:08.848933327 +0000
@@ -20,7 +20,7 @@
 SSH public key which should be allowed to log in to that account.
 
 If the account does not already exist on the system, it is created and added
-to /etc/sudoers to allow that account to administer the machine without needing
+to %%PREFIX%%/etc/sudoers to allow that account to administer the machine without needing
 a password.
 """
 
@@ -139,42 +139,42 @@
       return False
 
   def LockSudoers(self):
-    """Create an advisory lock on /etc/sudoers.tmp.
+    """Create an advisory lock on %%PREFIX%%/etc/sudoers.tmp.
 
     Returns:
       True if successful, False if not.
     """
     try:
-      f = self.os.open('/etc/sudoers.tmp', os.O_EXCL|os.O_CREAT)
+      f = self.os.open('%%PREFIX%%/etc/sudoers.tmp', os.O_EXCL|os.O_CREAT)
       self.os.close(f)
       return True
     except OSError as e:
       if e.errno == errno.EEXIST:
-        logging.warning('/etc/sudoers.tmp lock file already exists')
+        logging.warning('%%PREFIX%%/etc/sudoers.tmp lock file already exists')
       else:
-        logging.warning('Could not create /etc/sudoers.tmp lock file: %s', e)
+        logging.warning('Could not create %%PREFIX%%/etc/sudoers.tmp lock file: %s', e)
     return False
 
   def UnlockSudoers(self):
-    """Remove the advisory lock on /etc/sudoers.tmp."""
+    """Remove the advisory lock on %%PREFIX%%/etc/sudoers.tmp."""
     try:
-      self.os.unlink('/etc/sudoers.tmp')
+      self.os.unlink('%%PREFIX%%/etc/sudoers.tmp')
       return True
     except OSError as e:
       if e.errno == errno.ENOENT:
         return True
-      logging.warning('Could not remove /etc/sudoers.tmp: %s', e)
+      logging.warning('Could not remove %%PREFIX%%/etc/sudoers.tmp: %s', e)
       return False
 
   def MakeUserSudoer(self, user):
     """Add user to the sudoers file."""
     # If the user has no sudoers file, don't add an entry.
-    if not self.os.path.isfile('/etc/sudoers'):
-      logging.info('Did not grant admin access to %s. /etc/sudoers not found.',
+    if not self.os.path.isfile('%%PREFIX%%/etc/sudoers'):
+      logging.info('Did not grant admin access to %s. %%PREFIX%%/etc/sudoers not found.',
                    user)
       return
 
-    with self.system.OpenFile('/etc/sudoers', 'r') as sudoer_f:
+    with self.system.OpenFile('%%PREFIX%%/etc/sudoers', 'r') as sudoer_f:
       sudoer_lines = sudoer_f.readlines()
 
     if IsUserSudoerInLines(user, sudoer_lines):
@@ -184,13 +184,13 @@
 
     # Lock sudoers.
     if not self.LockSudoers():
-      logging.warning('Did not grant admin access to %s. /etc/sudoers locked.',
+      logging.warning('Did not grant admin access to %s. %%PREFIX%%/etc/sudoers locked.',
                       user)
       return
 
     try:
       # First read in the sudoers file (this time under the lock).
-      with self.system.OpenFile('/etc/sudoers', 'r') as sudoer_f:
+      with self.system.OpenFile('%%PREFIX%%/etc/sudoers', 'r') as sudoer_f:
         sudoer_lines = sudoer_f.readlines()
 
       if IsUserSudoerInLines(user, sudoer_lines):
@@ -213,15 +213,15 @@
               'Did not grant admin access to %s. Sudoers was invalid.', user)
           return
 
-        self.os.chmod('/etc/sudoers', 0640)
-        with self.system.OpenFile('/etc/sudoers', 'w') as sudoer_f:
+        self.os.chmod('%%PREFIX%%/etc/sudoers', 0640)
+        with self.system.OpenFile('%%PREFIX%%/etc/sudoers', 'w') as sudoer_f:
           sudoer_f.writelines(sudoer_lines)
           # Make sure we're still 0640.
           self.os.fchmod(sudoer_f.fileno(), stat.S_IWUSR | 0640)
           try:
             self.os.fchmod(sudoer_f.fileno(), 0440)
           except (IOError, OSError) as e:
-            logging.warning('Could not restore perms to /etc/sudoers: %s', e)
+            logging.warning('Could not restore perms to %%PREFIX%%/etc/sudoers: %s', e)
       finally:
         # Clean up the temp file.
         try:
