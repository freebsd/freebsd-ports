--- setup.py.orig	Sat Jun  9 12:16:40 2007
+++ setup.py	Sat Jun  9 12:19:31 2007
@@ -100,7 +100,7 @@
 	else:
 		boosttype = 'mt'
 	removals = ['-g', '-DNDEBUG', '-O2', '-Wstrict-prototypes']
-        additions = ['-DNDEBUG', '-O2']
+        additions = ['-DNDEBUG']
 
 	if python_version == '2.5':
 		cv_opt = sysconfig.get_config_vars()["CFLAGS"]
@@ -131,19 +131,21 @@
 # Ubuntu possible.
 if boosttype == "nomt":
 	librariestype = ['boost_filesystem', 'boost_date_time',
-			'boost_thread', 'z', 'pthread', 'ssl']
+			'boost_thread', 'z', 'ssl']
 	print 'Libraries nomt' 
 elif boosttype == "mt":
 	librariestype = ['boost_filesystem-mt', 'boost_date_time-mt',
-			'boost_thread-mt', 'z', 'pthread', 'ssl']
+			'boost_thread-mt', 'z', 'ssl']
 	print 'Libraries mt'
 
 deluge_core = Extension('deluge_core',
                     include_dirs = ['./libtorrent', './libtorrent/include', 
                     			'./libtorrent/include/libtorrent', 
-                    			'/usr/include/python' + python_version],
+                    			'%%LOCALBASE%%/include'],
+                    library_dirs = ['%%LOCALBASE%%/lib'],
 		    libraries = librariestype,
                     extra_compile_args = EXTRA_COMPILE_ARGS,
+                    extra_link_args = ['%%PTHREAD_LIBS%%'],
                     sources = ['src/deluge_core.cpp',
 					'libtorrent/src/alert.cpp',
 					'libtorrent/src/allocate_resources.cpp',
