--- setup.py.orig	Sat Aug 23 16:31:00 2003
+++ setup.py	Fri Dec  5 21:24:43 2003
@@ -33,7 +33,7 @@
       url = pygopherd.version.homepage,
       packages = ['pygopherd', 'pygopherd.handlers', 'pygopherd.protocols'],
       scripts = ['bin/pygopherd'],
-      data_files = [ ('/etc/pygopherd', ['conf/pygopherd.conf',
+      data_files = [ ('%%PREFIX%%/etc/pygopherd', ['conf/pygopherd.conf-dist',
                                          'conf/mime.types'] ) ],
       license = pygopherd.version.license
 )
