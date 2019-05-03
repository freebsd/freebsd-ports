--- setup.py
+++ setup.py
@@ -30,13 +30,14 @@ can be used for each of these R versions.
 See the files INSTALL.UNIX and INSTALL.WINDOWS for more details.
 """
 
-DEBUG=True
+DEBUG=False
 
 import os, os.path, sys, shutil, re
 from distutils.core import setup, Extension
 from distutils.sysconfig import *
 from distutils.errors import *
 import rpy_tools
+
 if sys.platform=="win32":
     import rpy_wintools
 
@@ -85,7 +86,7 @@ for RHOME in RHOMES:
         get_config_vars()['OPT'] = '-g -Wall'
     else:
         # to avoid strict prototypes errors from R includes
-        get_config_vars()['OPT'] = '-DNDEBUG -g -O3 -Wall'
+        get_config_vars()['OPT'] = '-DNDEBUG -O3 -Wall'
 
     # get the Python version
     if sys.version[:3] >= '2.2':
@@ -149,22 +150,21 @@ for RHOME in RHOMES:
         library_dirs= r_libs
         runtime_libs = r_libs
         extra_compile_args=[]
-    elif sys.platform=='osf1V5':
-        include_dirs = [ os.path.join(RHOME.strip(), 'include'), 
-                         'src' ]
-        libraries=['R','Rlapack']
-        library_dirs = r_libs
-        runtime_libs = r_libs
-        extra_compile_args=["-shared"]
-        source_files = source_files + ["src/setenv.c"]
+        
     else: # unix-like systems, this is known to work for Linux and Solaris
         include_dirs = [ os.path.join(RHOME.strip(), 'include'), 
                          'src', '/usr/share/R/include' ]
-        libraries=['R','Rlapack']
+
         library_dirs = r_libs
         runtime_libs = r_libs
         extra_compile_args=["-shared"]
         source_files = source_files + ["src/setenv.c"]
+        
+        libraries=['R']
+          
+        # Ask R to tell us how to properly link against lapack
+        extra_compile_args += [ rpy_tools.get_R_LAPACK_LIB_FLAGS( RHOME ) ]
+
 
     # Discover which array packages are present
     try: 
diff --git src/RPy.h src/RPy.h
index 04faf3d..614ae5a 100644
