--- src/webrtc/src/build/detect_host_arch.py.orig	2023-03-09 06:31:50 UTC
+++ src/webrtc/src/build/detect_host_arch.py
@@ -23,6 +23,8 @@ def HostArch():
         host_arch = 'arm'
     elif host_arch.startswith('aarch64'):
         host_arch = 'arm64'
+    elif host_arch.startswith('arm64'):
+        host_arch = 'arm64'
     elif host_arch.startswith('mips64'):
         host_arch = 'mips64'
     elif host_arch.startswith('mips'):
