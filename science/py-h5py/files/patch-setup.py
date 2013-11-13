--- ./setup.py.orig	2013-09-04 02:32:03.000000000 +0300
+++ ./setup.py	2013-10-30 23:46:03.668134592 +0200
@@ -136,8 +136,8 @@
         COMPILER_SETTINGS['include_dirs'] += ['/usr/local/include'] # homebrew
         COMPILER_SETTINGS['library_dirs'] += ['/usr/local/lib']     # homebrew
     elif sys.platform.startswith('freebsd'):
-        COMPILER_SETTINGS['include_dirs'] += ['/usr/local/include'] # homebrew
-        COMPILER_SETTINGS['library_dirs'] += ['/usr/local/lib']     # homebrew
+        COMPILER_SETTINGS['include_dirs'] += ['%%LOCALBASE%%/include'] # homebrew
+        COMPILER_SETTINGS['library_dirs'] += ['%%LOCALBASE%%/lib']     # homebrew
     if MPI:
         COMPILER_SETTINGS['include_dirs'] += [mpi4py.get_include()]
     COMPILER_SETTINGS['runtime_library_dirs'] = [op.abspath(x) for x in COMPILER_SETTINGS['library_dirs']]
