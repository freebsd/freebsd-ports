# Incorrect config file path since update to 0.29.1
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=233909
# TODO: Upstream

--- certbot/compat.py.orig	2019-01-24 22:07:15 UTC
+++ certbot/compat.py
@@ -184,6 +184,12 @@ LINUX_DEFAULT_FOLDERS = {
     'logs': '/var/log/letsencrypt',
 }
 
+FREEBSD_DEFAULT_FOLDERS = {
+    'config': '/usr/local/etc/letsencrypt',
+    'work': '/var/db/letsencrypt',
+    'logs': '/var/log/letsencrypt',
+}
+
 def get_default_folder(folder_type):
     """
     Return the relevant default folder for the current OS
@@ -195,7 +201,13 @@ def get_default_folder(folder_type):
 
     """
     if 'fcntl' in sys.modules:
-        # Linux specific
-        return LINUX_DEFAULT_FOLDERS[folder_type]
-    # Windows specific
-    return WINDOWS_DEFAULT_FOLDERS[folder_type]
+        # Unix-like
+        if sys.platform.startswith('freebsd') or sys.platform.startswith('dragonfly'):
+            # FreeBSD specific
+            return FREEBSD_DEFAULT_FOLDERS[folder_type]
+        else:
+            # Linux specific
+            return LINUX_DEFAULT_FOLDERS[folder_type]
+    else:
+        # Windows specific
+        return WINDOWS_DEFAULT_FOLDERS[folder_type]
