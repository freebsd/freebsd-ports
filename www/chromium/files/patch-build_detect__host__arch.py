--- build/detect_host_arch.py.orig	2020-11-13 06:36:34 UTC
+++ build/detect_host_arch.py
@@ -21,6 +21,8 @@ def HostArch():
     host_arch = 'ia32'
   elif host_arch in ['x86_64', 'amd64']:
     host_arch = 'x64'
+  elif host_arch.startswith('arm64'):
+    host_arch = 'arm64'
   elif host_arch.startswith('arm'):
     host_arch = 'arm'
   elif host_arch.startswith('aarch64'):
