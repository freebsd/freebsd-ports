--- setup.py.orig	2014-02-14 17:25:06 UTC
+++ setup.py
@@ -108,7 +108,7 @@ ext_modules = []
 
 if operatingSystem == 'mac':
     extra_link_args = ['-Wl,-framework', '-Wl,Accelerate', '-headerpad_max_install_names']
-elif operatingSystem == 'linux':
+elif operatingSystem == 'linux' or operatingSystem.startswith('freebsd'):
     extra_link_args = ['-lrt']
 else:
     # Assuming Windows
