--- setup.py.orig	Sun Sep  8 02:47:43 2002
+++ setup.py	Sun Sep  8 02:48:06 2002
@@ -34,7 +34,7 @@
       url = pygopherd.version.homepage,
       packages = ['pygopherd', 'pygopherd.handlers', 'pygopherd.protocols'],
       scripts = ['bin/pygopherd'],
-      data_files = [ ('/etc/pygopherd', ['conf/pygopherd.conf',
+      data_files = [ ('%%PREFIX%%/etc/pygopherd', ['conf/pygopherd.conf',
                                          'conf/mime.types'] ) ],
       license = pygopherd.version.license
 )
