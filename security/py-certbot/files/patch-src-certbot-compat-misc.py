# Incorrect config file path since update to 0.29.1
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=233909
# https://github.com/certbot/certbot/pull/6702
# https://github.com/certbot/certbot/pull/7056
# TODO: Upstream

--- src/certbot/compat/misc.py.orig	2023-04-04 15:06:41 UTC
+++ src/certbot/compat/misc.py
@@ -100,6 +100,11 @@ LINUX_DEFAULT_FOLDERS = {
     'work': '/var/lib/letsencrypt',
     'logs': '/var/log/letsencrypt',
 }
+FREEBSD_DEFAULT_FOLDERS = {
+    'config': '/usr/local/etc/letsencrypt',
+    'work': '/var/db/letsencrypt',
+    'logs': '/var/log/letsencrypt',
+}
 
 
 def get_default_folder(folder_type: str) -> str:
@@ -113,8 +118,13 @@ def get_default_folder(folder_type: str) -> str:
 
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
 
