--- azure/cli/command_modules/storage/azcopy/util.py.orig	2023-11-29 03:41:09 UTC
+++ azure/cli/command_modules/storage/azcopy/util.py
@@ -70,6 +70,8 @@ class AzCopy:
             file_url = base_url.format('linux', 'amd64', AZCOPY_VERSION, 'tar.gz')
         elif self.system == 'Darwin':
             file_url = base_url.format('darwin', 'amd64', AZCOPY_VERSION, 'zip')
+        elif self.system == 'FreeBSD':
+            raise CLIError('Azcopy ({}) binary not available, follow instructions at https://wiki.freebsd.org/Ports/sysutils/py-azure-cli'.format(self.system))
         else:
             raise CLIError('Azcopy ({}) does not exist.'.format(self.system))
         try:
@@ -206,7 +208,7 @@ def _get_default_install_location():
     _azcopy_installation_dir = os.path.join(_config_dir, "bin")
     if system == 'Windows':
         install_location = os.path.join(_azcopy_installation_dir, 'azcopy.exe')
-    elif system in ('Linux', 'Darwin'):
+    elif system in ('Linux', 'Darwin', 'FreeBSD'):
         install_location = os.path.join(_azcopy_installation_dir, 'azcopy')
     else:
         raise CLIError('The {} platform is not currently supported. If you want to know which platforms are supported, '
