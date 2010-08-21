--- setup.py.orig	2010-08-20 18:20:27.000000000 -0300
+++ setup.py	2010-08-21 16:49:05.000000000 -0300
@@ -68,7 +68,6 @@
     "-D_FILE_OFFSET_BITS=64",
     "-DNDEBUG",
     "-DTORRENT_USE_OPENSSL=1",
-    "-O2",
     ]
 
 if windows_check():
@@ -115,12 +114,14 @@
 remove_from_cflags(removals)
 
 _library_dirs = [
+    '%%LOCALBASE%%/lib'
 ]
 
 _include_dirs = [
     './libtorrent',
     './libtorrent/include',
-    './libtorrent/include/libtorrent'
+    './libtorrent/include/libtorrent',
+    '%%LOCALBASE%%/include'
 ]
 
 if windows_check():
@@ -142,14 +143,6 @@
         'zlib'
     ]
 else:
-    _include_dirs += [
-        '/usr/include/python' + python_version,
-        sysconfig.get_config_var("INCLUDEDIR")
-        ]
-    for include in os.environ.get("INCLUDEDIR", "").split(":"):
-        _include_dirs.append(include)
-
-    _library_dirs += [sysconfig.get_config_var("LIBDIR"), '/opt/local/lib']
     if osx_check():
         _include_dirs += [
             '/opt/local/include/boost-1_35',
@@ -163,7 +156,6 @@
         'boost_iostreams',
         'boost_python',
         'boost_thread',
-        'pthread',
         'ssl',
         'z'
         ]
@@ -212,6 +204,7 @@
     build_libtorrent = True
 else:
     build_libtorrent = False
+build_libtorrent = False
 
 if build_libtorrent:
     got_libtorrent = False
@@ -392,8 +385,6 @@
         for cmd_name in self.get_sub_commands():
             self.run_command(cmd_name)
         _install.run(self)
-        if not self.root:
-            self.do_egg_install()
 
 cmdclass = {
     'build': build,
@@ -409,7 +400,7 @@
 
 # Data files to be installed to the system
 _data_files = [
-    ('share/icons/scalable/apps', ['deluge/data/icons/scalable/apps/deluge.svg']),
+    ('share/icons/hicolor/scalable/apps', ['deluge/data/icons/scalable/apps/deluge.svg']),
     ('share/icons/hicolor/128x128/apps', ['deluge/data/icons/hicolor/128x128/apps/deluge.png']),
     ('share/icons/hicolor/16x16/apps', ['deluge/data/icons/hicolor/16x16/apps/deluge.png']),
     ('share/icons/hicolor/192x192/apps', ['deluge/data/icons/hicolor/192x192/apps/deluge.png']),
@@ -424,7 +415,7 @@
     ('share/icons/hicolor/96x96/apps', ['deluge/data/icons/hicolor/96x96/apps/deluge.png']),
     ('share/applications', ['deluge/data/share/applications/deluge.desktop']),
     ('share/pixmaps', ['deluge/data/pixmaps/deluge.png', 'deluge/data/pixmaps/deluge.xpm']),
-    ('share/man/man1', [
+    ('man/man1', [
         'docs/man/deluge.1',
         'docs/man/deluged.1',
         'docs/man/deluge-gtk.1',
