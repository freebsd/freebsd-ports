# Incorrect config file path since update to 0.29.1
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=233909
# https://github.com/certbot/certbot/pull/6702
# https://github.com/certbot/certbot/pull/7056
# TODO: Upstream

--- certbot/compat/misc.py.orig	2021-03-02 21:37:04 UTC
+++ certbot/compat/misc.py
@@ -79,6 +79,11 @@ LINUX_DEFAULT_FOLDERS = {
     'work': '/var/lib/letsencrypt',
     'logs': '/var/log/letsencrypt',
 }
+FREEBSD_DEFAULT_FOLDERS = {
+    'config': '/usr/local/etc/letsencrypt',
+    'work': '/var/db/letsencrypt',
+    'logs': '/var/log/letsencrypt',
+}
 
 
 def get_default_folder(folder_type):
@@ -93,8 +98,13 @@ def get_default_folder(folder_type):
 
     """
     if os.name != 'nt':
-        # Linux specific
-        return LINUX_DEFAULT_FOLDERS[folder_type]
+        # Unix-like
+        if sys.platform.startswith('freebsd') or sys.platform.startswith('dragonfly'):
+            # FreeBSD specific
+            return FREEBSD_DEFAULT_FOLDERS[folder_type]
+        else:
+            # Linux specific
+            return LINUX_DEFAULT_FOLDERS[folder_type]
     # Windows specific
     return WINDOWS_DEFAULT_FOLDERS[folder_type]
 
