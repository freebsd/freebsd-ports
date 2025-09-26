--- cargo-crates/v8-137.2.1/build/detect_host_arch.py.orig	2020-06-26 16:27:54 UTC
+++ cargo-crates/v8-137.2.1/build/detect_host_arch.py
@@ -24,6 +24,8 @@ def HostArch():
     host_arch = 'arm'
   elif host_arch.startswith('aarch64'):
     host_arch = 'arm64'
+  elif host_arch.startswith('arm64'):
+    host_arch = 'arm64'
   elif host_arch.startswith('mips64'):
     host_arch = 'mips64'
   elif host_arch.startswith('mips'):
