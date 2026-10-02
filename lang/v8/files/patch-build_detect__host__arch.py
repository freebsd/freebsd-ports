--- build/detect_host_arch.py.orig	2026-09-13 16:54:58 UTC
+++ build/detect_host_arch.py
@@ -19,10 +19,10 @@ def HostArch():
         host_arch = 'ia32'
     elif host_arch in ['x86_64', 'amd64']:
         host_arch = 'x64'
+    elif host_arch.startswith('arm64') or host_arch.startswith('aarch64'):
+        host_arch = 'arm64'
     elif host_arch.startswith('arm'):
         host_arch = 'arm'
-    elif host_arch.startswith('aarch64'):
-        host_arch = 'arm64'
     elif host_arch.startswith('mips64'):
         host_arch = 'mips64'
     elif host_arch.startswith('mips'):
