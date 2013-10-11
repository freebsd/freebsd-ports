--- uwsgiconfig.py.bak	2013-10-11 07:59:20.000000000 +0400
+++ uwsgiconfig.py	2013-10-11 15:06:52.000000000 +0400
@@ -694,15 +694,6 @@
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
         if uwsgi_os == 'GNU/kFreeBSD':
             if self.has_include('execinfo.h'):
                 self.cflags.append('-DUWSGI_HAS_EXECINFO')
