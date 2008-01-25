--- setup.py.orig	2008-01-19 12:43:31.000000000 -0600
+++ setup.py	2008-01-19 12:45:24.000000000 -0600
@@ -103,13 +103,13 @@
                 "-DHAVE_INCLUDE_LIBTORRENT_ASIO_SSL_STREAM_HPP=1", 
                 "-DHAVE_INCLUDE_LIBTORRENT_ASIO_IP_TCP_HPP=1", 
                 "-DHAVE_PTHREAD=1", "-DTORRENT_USE_OPENSSL=1", "-DHAVE_SSL=1", 
-                "-DNDEBUG=1", "-O2"]
+                "-DNDEBUG=1"]
     if ARCH == "x64":
         EXTRA_COMPILE_ARGS.append("-DAMD64")
 
     includedirs = ['./libtorrent', './libtorrent/include', 
                      './libtorrent/include/libtorrent', 
-                     '/usr/include/python' + python_version]
+                     '%%LOCALBASE%%/include']
 
     if OS == "linux":
         if os.path.exists(os.path.join(sysconfig.get_config_vars()['LIBDIR'], \
@@ -148,7 +148,7 @@
         boost_thread = "boost_thread-mt"
 
     librariestype = [boost_filesystem, boost_date_time,
-            boost_thread, 'z', 'pthread', 'ssl', 'rt', 'crypto']
+            boost_thread, 'z', 'ssl', 'crypto']
     
     removals = ['-g', '-Wstrict-prototypes']
 
@@ -202,8 +202,10 @@
     sources.remove('libtorrent/src/file_win.cpp')
     deluge_core = Extension('deluge_core',
                     include_dirs = includedirs,
+                    library_dirs = ['%%LOCALBASE%%/lib'],
                     libraries = librariestype,
                     extra_compile_args = EXTRA_COMPILE_ARGS,
+                    extra_link_args = ['%%PTHREAD_LIBS%%'],
                     sources = sources)
 else:
     sources.remove('libtorrent\\src\\file.cpp')
