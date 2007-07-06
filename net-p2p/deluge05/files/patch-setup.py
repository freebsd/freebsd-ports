--- setup.py.orig	Thu Jul  5 22:49:16 2007
+++ setup.py	Thu Jul  5 22:55:47 2007
@@ -105,7 +105,7 @@
 
 	includedirs = ['./libtorrent', './libtorrent/include', 
                      './libtorrent/include/libtorrent', 
-                     '/usr/include/python' + python_version]
+                     '%%LOCALBASE%%/include']
 
 	if OS == "linux":
 		if os.WEXITSTATUS(os.system('grep -iq "Debian GNU/Linux 4.0\|Ubuntu 7.04\|Ubuntu 6.06\|Ubuntu 6.10\|Fedora Core release 6\|openSUSE 10.2\|Mandriva Linux release 2007.1\|Fedora release 7" /etc/issue')) == 0:
@@ -117,7 +117,7 @@
 	else:
 		boosttype = 'mt'
 	removals = ['-g', '-Wstrict-prototypes']
-        additions = ['-DNDEBUG', '-O2']
+        additions = ['-DNDEBUG']
 
 	if python_version == '2.5':
 		cv_opt = sysconfig.get_config_vars()["CFLAGS"]
@@ -152,11 +152,11 @@
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
 
 def fetchCpp():
@@ -175,8 +175,10 @@
 
 deluge_core = Extension('deluge_core',
                     include_dirs = includedirs,
+                    library_dirs = ['%%LOCALBASE%%/lib'],
 		    libraries = librariestype,
                     extra_compile_args = EXTRA_COMPILE_ARGS,
+                    extra_link_args = ['%%PTHREAD_LIBS%%'],
                     sources = sources)
 # Thanks to Iain Nicol for code to save the location for installed prefix
 # At runtime, we need to know where we installed the data to.
