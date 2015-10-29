--- uwsgiconfig.py.orig	2015-10-07 04:34:01 UTC
+++ uwsgiconfig.py
@@ -784,15 +784,6 @@ class uConf(object):
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
