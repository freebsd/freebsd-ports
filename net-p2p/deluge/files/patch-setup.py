--- setup.py.orig	2007-08-14 11:14:32.000000000 -0500
+++ setup.py	2007-08-14 11:16:15.000000000 -0500
@@ -101,13 +101,13 @@
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
@@ -150,11 +150,11 @@
 # Ubuntu possible.
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
 
 def fetchCpp():
@@ -173,8 +173,10 @@
 
 deluge_core = Extension('deluge_core',
                     include_dirs = includedirs,
+                    library_dirs = ['%%LOCALBASE%%/lib'],
             libraries = librariestype,
                     extra_compile_args = EXTRA_COMPILE_ARGS,
+                    extra_link_args = ['%%PTHREAD_LIBS%%'],
                     sources = sources)
 # Thanks to Iain Nicol for code to save the location for installed prefix
 # At runtime, we need to know where we installed the data to.
