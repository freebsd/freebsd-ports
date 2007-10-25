--- setup.py.orig	2007-10-25 16:49:47.000000000 -0500
+++ setup.py	2007-10-25 16:51:47.000000000 -0500
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
         if os.WEXITSTATUS(os.system('grep -iq "Debian GNU/Linux 4.0\|Ubuntu 7.04\|Ubuntu 6.06\|Ubuntu 6.10\|Fedora Core release 6\|openSUSE 10.2\|Mandriva Linux release 2007.1\|Fedora release 7\|BLAG release 60001\|Yellow Dog Linux release 5.0 (Phoenix)\|CentOS release 5 (Final)" /etc/issue')) == 0:
@@ -164,11 +164,11 @@
 if not OS == "win":
     if boosttype == "nomt":
         librariestype = ['boost_filesystem', 'boost_date_time',
-            'boost_thread', 'z', 'pthread', 'ssl']
+            'boost_thread', 'z', 'ssl']
         print 'Libraries nomt' 
     elif boosttype == "mt":
         librariestype = ['boost_filesystem-mt', 'boost_date_time-mt',
-            'boost_thread-mt', 'z', 'pthread', 'ssl']
+            'boost_thread-mt', 'z', 'ssl']
         print 'Libraries mt'
 else:
         librariestype = ['boost_filesystem-mt', 'boost_date_time-mt',
@@ -189,8 +189,10 @@
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
