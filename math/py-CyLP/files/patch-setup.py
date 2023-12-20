--- setup.py.orig	2023-11-01 20:21:56 UTC
+++ setup.py
@@ -124,7 +124,7 @@ ext_modules = []
 
 if operatingSystem == 'mac':
     extra_link_args = ['-Wl,-framework', '-Wl,Accelerate', '-headerpad_max_install_names']
-elif operatingSystem == 'linux':
+elif operatingSystem == 'linux' or operatingSystem.startswith('freebsd'):
     extra_link_args = ['-lrt']
 else:
     # Assuming Windows
@@ -396,7 +396,7 @@ s_AUTHORS = open('AUTHORS').read()
 
 extra_files = ['cpp/*.hpp', 'cpp/*.h', 'cy/*.pxd', 'VERSION']
 
-setup(name='cylp',
+setup(name='CyLP',
       version=VERSION,
       description='A Python interface for CLP, CBC, and CGL',
       long_description=s_README,
