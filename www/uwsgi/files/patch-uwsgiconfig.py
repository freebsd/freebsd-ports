--- uwsgiconfig.py.orig	2013-05-26 10:08:32.000000000 +0400
+++ uwsgiconfig.py	2013-06-03 15:21:58.000000000 +0400
@@ -613,15 +613,6 @@
             self.cflags.append('-DUWSGI_HAS_IFADDRS')
             report['ifaddrs'] = True
 
-        if uwsgi_os in ('FreeBSD', 'OpenBSD'):
-            if self.has_include('execinfo.h') or os.path.exists('/usr/local/include/execinfo.h'):
-                if os.path.exists('/usr/local/include/execinfo.h'):
-                    self.cflags.append('-I/usr/local/include')
-                    self.ldflags.append('-L/usr/local/lib')
-                self.cflags.append('-DUWSGI_HAS_EXECINFO')
-                self.libs.append('-lexecinfo')
-                report['execinfo'] = True
-
         if self.has_include('zlib.h'):
             self.cflags.append('-DUWSGI_ZLIB')
             self.libs.append('-lz')
