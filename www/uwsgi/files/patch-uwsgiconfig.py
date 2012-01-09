--- uwsgiconfig.py~	2012-01-03 17:12:16.000000000 +0100
+++ uwsgiconfig.py	2012-01-09 21:51:45.286212946 +0100
@@ -531,7 +531,7 @@
                     self.gcc_list.append('regexp')
                     self.cflags.append("-DUWSGI_PCRE")
 
-        if self.has_include('sys/capability.h'):
+        if uwsgi_os != 'FreeBSD' and self.has_include('sys/capability.h'):
             self.cflags.append("-DUWSGI_CAP")
             self.libs.append('-lcap')
 
