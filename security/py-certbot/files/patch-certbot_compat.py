# Incorrect config file path since update to 0.29.1
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=233909
# TODO: Upstream

--- certbot/compat.py.orig	2018-12-05 23:47:58 UTC
+++ certbot/compat.py
@@ -183,6 +183,11 @@ LINUX_DEFAULT_FOLDERS = {
     'work': '/var/lib/letsencrypt',
     'logs': '/var/log/letsencrypt',
 }
+FREEBSD_DEFAULT_FOLDERS = {
+    'config': '%%LOCALBASE%%/etc/letsencrypt',
+    'work': '/var/db/letsencrypt',
+    'logs': '/var/log/letsencrypt',
+}
 
 def get_default_folder(folder_type):
     """
@@ -195,7 +200,13 @@ def get_default_folder(folder_type):
 
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
