--- setup.py.orig	2008-05-01 11:22:01.000000000 -0500
+++ setup.py	2008-05-01 11:24:16.000000000 -0500
@@ -103,14 +103,14 @@
                 "-DHAVE_INCLUDE_LIBTORRENT_ASIO_SSL_STREAM_HPP=1", 
                 "-DHAVE_INCLUDE_LIBTORRENT_ASIO_IP_TCP_HPP=1", 
                 "-DHAVE_PTHREAD=1", "-DTORRENT_USE_OPENSSL=1", "-DHAVE_SSL=1", 
-                "-DNDEBUG=1", '-O2']
+                "-DNDEBUG=1"]
 # Done through debian/rules, as all arches are not handled
 #    if ARCH == "x64":
 #        EXTRA_COMPILE_ARGS.append("-DAMD64")
 
     includedirs = ['./libtorrent', './libtorrent/include', 
                      './libtorrent/include/libtorrent', 
-                     '/usr/include/python' + python_version]
+                     '%%LOCALBASE%%/include']
 
     if OS == "linux":
         if os.path.exists(os.path.join(sysconfig.get_config_vars()['LIBDIR'], \
@@ -149,7 +149,7 @@
         boost_thread = "boost_thread-mt"
 
     librariestype = [boost_filesystem, boost_date_time,
-            boost_thread, 'z', 'pthread', 'ssl', 'crypto']
+            boost_thread, 'z', 'ssl', 'crypto']
 
     if os == "linux":
         librariestype += ['rt']
@@ -210,8 +210,10 @@
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
