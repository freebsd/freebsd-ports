--- build/detect_host_arch.py.orig	2019-04-04 10:22:51.354518000 +0200
+++ build/detect_host_arch.py	2019-04-04 10:23:07.641855000 +0200
@@ -19,6 +19,8 @@ def HostArch():
     host_arch = 'ia32'
   elif host_arch in ['x86_64', 'amd64']:
     host_arch = 'x64'
+  elif host_arch.startswith('arm64'):
+    host_arch = 'arm64'
   elif host_arch.startswith('arm'):
     host_arch = 'arm'
   elif host_arch.startswith('aarch64'):
