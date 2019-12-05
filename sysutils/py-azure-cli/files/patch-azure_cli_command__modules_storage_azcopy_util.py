--- azure/cli/command_modules/storage/azcopy/util.py.orig	2019-12-04 23:30:55 UTC
+++ azure/cli/command_modules/storage/azcopy/util.py
@@ -41,6 +41,8 @@ class AzCopy(object):
                 file_url = base_url.format('linux', 'tar.gz')
             elif self.system == 'Darwin':
                 file_url = base_url.format('darwin', 'zip')
+            elif self.system == 'FreeBSD':
+                raise CLIError('Azcopy ({}) binary not available, follow instructions at https://wiki.freebsd.org/Ports/sysutils/py-azure-cli'.format(self.system))
             else:
                 raise CLIError('Azcopy ({}) does not exist.'.format(self.system))
             try:
@@ -163,7 +165,7 @@ def _get_default_install_location():
         if not home_dir:
             return None
         install_location = os.path.join(home_dir, r'.azcopy\azcopy.exe')
-    elif system in ('Linux', 'Darwin'):
+    elif system in ('Linux', 'Darwin', 'FreeBSD'):
         install_location = os.path.expanduser(os.path.join('~', 'bin/azcopy'))
     else:
         install_location = None
