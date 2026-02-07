--- setup.py.orig	2022-04-06 17:42:24 UTC
+++ setup.py
@@ -43,13 +43,13 @@ if sys.platform == 'win32':
     macros.append(('WIN32', '1'))
 
 # HACK replace linker gcc with g++
-from distutils import sysconfig
+import sysconfig
 save_init_posix = sysconfig._init_posix
 
 
-def my_init_posix():
-    save_init_posix()
-    g = sysconfig._config_vars
+def my_init_posix(vars):
+    save_init_posix(vars)
+    g = sysconfig._CONFIG_VARS
     compiler = g['LDSHARED'].split()[0]
     flags = g['LDSHARED'].split()[1:]
     if compiler == 'gcc':
@@ -77,10 +77,6 @@ setup(name=PACKAGE_NAME,
           define_macros=macros,
           include_dirs=include_dirs,
           library_dirs=library_dirs,
-          libraries=libraries)],
+          libraries=libraries)]
       # scripts=['tests/pcapytests.py', 'tests/96pings.pcap'],
-      data_files=[
-          (os.path.join('share', 'doc', PACKAGE_NAME),
-              ['README', 'LICENSE', 'pcapy.html']),
-          ('tests', ['tests/pcapytests.py', 'tests/96pings.pcap'])]
       )
