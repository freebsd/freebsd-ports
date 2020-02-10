--- azure/cli/command_modules/storage/azcopy/util.py.orig	2020-01-31 12:42:39 UTC
+++ azure/cli/command_modules/storage/azcopy/util.py
@@ -50,6 +50,8 @@ class AzCopy(object):
             file_url = base_url.format('linux', 'amd64', AZCOPY_VERSION, 'tar.gz')
         elif self.system == 'Darwin':
             file_url = base_url.format('darwin', 'amd64', AZCOPY_VERSION, 'zip')
+        elif self.system == 'FreeBSD':
+            raise CLIError('Azcopy ({}) binary not available, follow instructions at https://wiki.freebsd.org/Ports/sysutils/py-azure-cli'.format(self.system))
         else:
             raise CLIError('Azcopy ({}) does not exist.'.format(self.system))
         try:
@@ -180,7 +182,7 @@ def _get_default_install_location():
         if not home_dir:
             return None
         install_location = os.path.join(home_dir, r'.azcopy\azcopy.exe')
-    elif system in ('Linux', 'Darwin'):
+    elif system in ('Linux', 'Darwin', 'FreeBSD'):
         install_location = os.path.expanduser(os.path.join('~', 'bin/azcopy'))
     else:
         install_location = None
