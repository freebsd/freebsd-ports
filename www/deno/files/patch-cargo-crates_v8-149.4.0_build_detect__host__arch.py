--- cargo-crates/v8-149.4.0/build/detect_host_arch.py.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/v8-149.4.0/build/detect_host_arch.py
@@ -24,6 +24,8 @@ def HostArch():
     host_arch = 'arm'
   elif host_arch.startswith('aarch64'):
     host_arch = 'arm64'
+  elif host_arch.startswith('arm64'):
+    host_arch = 'arm64'
   elif host_arch.startswith('mips64'):
     host_arch = 'mips64'
   elif host_arch.startswith('mips'):
