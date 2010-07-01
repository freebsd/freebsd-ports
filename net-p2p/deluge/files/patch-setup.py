--- setup.py.orig	2010-01-10 06:16:08.000000000 +0900
+++ setup.py	2010-01-13 16:48:06.000000000 +0900
@@ -67,7 +67,6 @@
     "-D_FILE_OFFSET_BITS=64",
     "-DNDEBUG",
     "-DTORRENT_USE_OPENSSL=1",
-    "-O2",
     ]
 
 if windows_check():
@@ -113,12 +112,14 @@
         sysconfig.get_config_vars()["OPT"] = " ".join(cv_opt.split())
 
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
@@ -140,14 +141,6 @@
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
@@ -161,7 +154,6 @@
         'boost_iostreams',
         'boost_python',
         'boost_thread',
-        'pthread',
         'ssl',
         'z'
         ]
@@ -204,12 +196,6 @@
 
 # Check for a system libtorrent and if found, then do not build the libtorrent extension
 build_libtorrent = True
-try:
-    from deluge._libtorrent import lt
-except ImportError:
-    build_libtorrent = True
-else:
-    build_libtorrent = False
 
 if build_libtorrent and os.path.exists("libtorrent"):
     # There isn't a system libtorrent library, so let's build the one included with deluge
@@ -219,6 +205,7 @@
         include_dirs = _include_dirs,
         libraries = _libraries,
         library_dirs = _library_dirs,
+        extra_link_args = ['%%PTHREAD_LIBS%%'],
         sources = _sources
     )
 
@@ -356,8 +343,8 @@
         for cmd_name in self.get_sub_commands():
             self.run_command(cmd_name)
         _install.run(self)
-        if not self.root:
-            self.do_egg_install()
+#        if not self.root:
+#            self.do_egg_install()
 
 cmdclass = {
     'build': build,
@@ -371,7 +358,7 @@
 
 # Data files to be installed to the system
 _data_files = [
-    ('share/icons/scalable/apps', ['deluge/data/icons/scalable/apps/deluge.svg']),
+    ('share/icons/hicolor/scalable/apps', ['deluge/data/icons/scalable/apps/deluge.svg']),
     ('share/icons/hicolor/128x128/apps', ['deluge/data/icons/hicolor/128x128/apps/deluge.png']),
     ('share/icons/hicolor/16x16/apps', ['deluge/data/icons/hicolor/16x16/apps/deluge.png']),
     ('share/icons/hicolor/192x192/apps', ['deluge/data/icons/hicolor/192x192/apps/deluge.png']),
@@ -386,7 +373,7 @@
     ('share/icons/hicolor/96x96/apps', ['deluge/data/icons/hicolor/96x96/apps/deluge.png']),
     ('share/applications', ['deluge/data/share/applications/deluge.desktop']),
     ('share/pixmaps', ['deluge/data/pixmaps/deluge.png', 'deluge/data/pixmaps/deluge.xpm']),
-    ('share/man/man1', [
+    ('man/man1', [
         'docs/man/deluge.1',
         'docs/man/deluged.1',
         'docs/man/deluge-gtk.1',
