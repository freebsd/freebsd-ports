--- build/detect_host_arch.py.orig	2026-09-25 15:26:43 UTC
+++ build/detect_host_arch.py
@@ -23,6 +23,8 @@ def HostArch():
         host_arch = 'arm'
     elif host_arch.startswith('aarch64'):
         host_arch = 'arm64'
+    elif host_arch.startswith('arm64'):
+        host_arch = 'arm64'
     elif host_arch.startswith('mips64'):
         host_arch = 'mips64'
     elif host_arch.startswith('mips'):
