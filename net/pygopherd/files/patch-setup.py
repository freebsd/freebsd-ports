--- setup.py.orig	2005-09-22 13:00:21 UTC
+++ setup.py
@@ -33,7 +33,7 @@ setup(name = "pygopherd",
       url = pygopherd.version.homepage,
       packages = ['pygopherd', 'pygopherd.handlers', 'pygopherd.protocols'],
       scripts = ['bin/pygopherd'],
-      data_files = [ ('/etc/pygopherd', ['conf/pygopherd.conf',
+      data_files = [ ('%%PREFIX%%/etc/pygopherd', ['conf/pygopherd.conf.sample',
                                          'conf/mime.types'] ) ],
       license = pygopherd.version.license
 )
