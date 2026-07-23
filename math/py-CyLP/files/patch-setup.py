-- Add FreeBSD to the Unix platform branch so -lrt is used and the Windows
-- /EHsc flag is not added on FreeBSD.
--- setup.py.orig	2026-07-22 22:18:35 UTC
+++ setup.py
@@ -124,7 +124,7 @@ if operatingSystem == 'mac':
 
 if operatingSystem == 'mac':
     extra_link_args = ['-Wl,-framework', '-Wl,Accelerate', '-headerpad_max_install_names']
-elif operatingSystem == 'linux':
+elif operatingSystem == 'linux' or operatingSystem.startswith('freebsd'):
     extra_link_args = ['-lrt']
 else:
     # Assuming Windows
