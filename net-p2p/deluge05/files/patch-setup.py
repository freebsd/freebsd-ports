--- setup.py.orig	Tue Mar  6 21:43:47 2007
+++ setup.py	Tue Mar  6 21:45:44 2007
@@ -51,7 +51,7 @@
 #
 
 removals = ['-g', '-DNDEBUG', '-O2', '-Wstrict-prototypes']
-additions = ['-DNDEBUG', '-O2']
+additions = ['-DNDEBUG']
 
 if pythonVersion == '2.5':
 	cv_opt = sysconfig.get_config_vars()["CFLAGS"]
@@ -85,12 +85,14 @@
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
