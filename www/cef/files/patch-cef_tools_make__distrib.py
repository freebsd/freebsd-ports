--- cef/tools/make_distrib.py.orig	2026-09-06 17:31:54 UTC
+++ cef/tools/make_distrib.py
@@ -745,7 +745,8 @@ def get_platform(sys_platform):
     return 'windows'
   if sys_platform == 'darwin':
     return 'mac'
-  if sys_platform.startswith('linux'):
+  if sys_platform.startswith(('linux', 'freebsd', 'openbsd')):
+    # The BSDs use the Linux (Ozone/X11) configuration.
     return 'linux'
   return ''
 
@@ -856,14 +857,19 @@ def main(argv=None):
   # src directory
   src_dir = os.path.realpath(os.path.join(cef_dir, os.pardir))
 
-  if not git.is_checkout(cef_dir):
+  if git.is_checkout(cef_dir):
+    # retrieve information for CEF
+    cef_url = git.get_url(cef_dir)
+    cef_rev = git.get_hash(cef_dir)
+    cef_commit_number = git.get_commit_number(cef_dir)
+  elif 'CEF_TARBALL_COMMIT_HASH' in os.environ:
+    # Using a source tarball, see tools/cef_version.py.
+    cef_url = 'https://github.com/chromiumembedded/cef.git'
+    cef_rev = os.environ['CEF_TARBALL_COMMIT_HASH']
+    cef_commit_number = os.environ.get('CEF_TARBALL_COMMIT_NUMBER', '0')
+  else:
     raise Exception('Not a valid checkout: %s' % (cef_dir))
 
-  # retrieve information for CEF
-  cef_url = git.get_url(cef_dir)
-  cef_rev = git.get_hash(cef_dir)
-  cef_commit_number = git.get_commit_number(cef_dir)
-
   # retrieve information for Chromium
   if git.is_checkout(src_dir):
     chromium_url = git.get_url(src_dir)
@@ -1488,14 +1494,17 @@ def main(argv=None):
     libcef_so = 'libcef.so'
     # yapf: disable
     binaries = [
-        {'path': 'chrome_sandbox', 'out_path': 'chrome-sandbox'},
+        {'path': 'chrome_sandbox', 'out_path': 'chrome-sandbox',
+         'conditional': not sys.platform.startswith('linux')},
         {'path': libcef_so},
         {'path': 'libEGL.so'},
         {'path': 'libGLESv2.so'},
-        {'path': 'libvk_swiftshader.so'},
+        {'path': 'libvk_swiftshader.so',
+         'conditional': not sys.platform.startswith('linux')},
         {'path': 'libvulkan.so.1'},
         {'path': 'v8_context_snapshot.bin'},
-        {'path': 'vk_swiftshader_icd.json'},
+        {'path': 'vk_swiftshader_icd.json',
+         'conditional': not sys.platform.startswith('linux')},
     ]
     # yapf: enable
     if options.ozone:
