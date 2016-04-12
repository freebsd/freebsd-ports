diff --git a/salt/modules/win_dacl.py b/salt/modules/win_dacl.py
index d57bb7b..d9ee27a 100644
--- salt/modules/win_dacl.py
+++ salt/modules/win_dacl.py
@@ -44,9 +44,10 @@ class daclConstants(object):
     # in ntsecuritycon has the extra bits 0x200 enabled.
     # Note that you when you set this permission what you'll generally get back is it
     # ORed with 0x200 (SI_NO_ACL_PROTECT), which is what ntsecuritycon incorrectly defines.
-    FILE_ALL_ACCESS = (ntsecuritycon.STANDARD_RIGHTS_REQUIRED | ntsecuritycon.SYNCHRONIZE | 0x1ff)
 
     def __init__(self):
+        self.FILE_ALL_ACCESS = (ntsecuritycon.STANDARD_RIGHTS_REQUIRED | ntsecuritycon.SYNCHRONIZE | 0x1ff)
+
         self.hkeys_security = {
             'HKEY_LOCAL_MACHINE': 'MACHINE',
             'HKEY_USERS': 'USERS',
@@ -88,7 +89,7 @@ def __init__(self):
                     ntsecuritycon.DELETE,
                     'TEXT': 'modify'},
                 'FULLCONTROL': {
-                    'BITS': daclConstants.FILE_ALL_ACCESS,
+                    'BITS': self.FILE_ALL_ACCESS,
                     'TEXT': 'full control'}
             }
         }
@@ -368,7 +369,7 @@ def add_ace(path, objectType, user, permission, acetype, propagation):
     path:  path to the object (i.e. c:\\temp\\file, HKEY_LOCAL_MACHINE\\SOFTWARE\\KEY, etc)
     user: user to add
     permission:  permissions for the user
-    acetypes:  either allow/deny for each user/permission (ALLOW, DENY)
+    acetype:  either allow/deny for each user/permission (ALLOW, DENY)
     propagation: how the ACE applies to children for Registry Keys and Directories(KEY, KEY&SUBKEYS, SUBKEYS)
 
     CLI Example:
