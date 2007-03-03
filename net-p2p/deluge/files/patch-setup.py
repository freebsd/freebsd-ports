--- setup.py.orig	Thu Mar  1 18:27:45 2007
+++ setup.py	Fri Mar  2 18:38:43 2007
@@ -44,7 +44,7 @@
 #
 
 removals = ['-g', '-DNDEBUG', '-O2', '-Wstrict-prototypes']
-additions = ['-DNDEBUG', '-O2']
+additions = ['-DNDEBUG']
 
 if pythonVersion == '2.5':
 	cv_opt = sysconfig.get_config_vars()["CFLAGS"]
@@ -78,12 +78,14 @@
 deluge_core = Extension('deluge_core',
                     include_dirs = ['./libtorrent', './libtorrent/include', 
                     			'./libtorrent/include/libtorrent', 
-                    			'/usr/include/python' + pythonVersion],
+                    			'%%LOCALBASE%%/include'],
+                    library_dirs = ['%%LOCALBASE%%/lib'],
                     libraries = ['boost_filesystem', 'boost_date_time',
 					'boost_program_options', 'boost_regex',
 					'boost_serialization', 'boost_thread', 
-					'z', 'pthread'],
+					'z'],
                     extra_compile_args = ["-Wno-missing-braces"],
+                    extra_link_args = ['%%PTHREAD_LIBS%%'],
                     sources = ['src/deluge_core.cpp',
 					'libtorrent/src/alert.cpp',
 					'libtorrent/src/allocate_resources.cpp',
