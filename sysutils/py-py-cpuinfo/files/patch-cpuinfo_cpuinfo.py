--- cpuinfo/cpuinfo.py.orig	2023-05-24 07:26:57 UTC
+++ cpuinfo/cpuinfo.py
@@ -797,7 +797,7 @@ def _parse_arch(arch_string_raw):
 	elif re.match(r'^armv8-a|aarch64|arm64$', arch_string_raw):
 		arch = 'ARM_8'
 		bits = 64
-	elif re.match(r'^armv7$|^armv7[a-z]$|^armv7-[a-z]$|^armv6[a-z]$', arch_string_raw):
+	elif re.match(r'^armv7$|^armv7[a-z]$|^armv7-[a-z]$|^armv6[a-z]$|^arm$', arch_string_raw):
 		arch = 'ARM_7'
 		bits = 32
 	elif re.match(r'^armv8$|^armv8[a-z]$|^armv8-[a-z]$', arch_string_raw):
