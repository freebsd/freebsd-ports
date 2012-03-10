--- setup.py.orig	2012-03-05 04:41:43.000000000 +0400
+++ setup.py	2012-03-10 14:17:07.000000000 +0400
@@ -206,7 +206,6 @@
 _ext_modules = []
 
 # Check for a system libtorrent and if found, then do not build the libtorrent extension
-build_libtorrent = True
 try:
     from deluge._libtorrent import lt
 except ImportError:
@@ -214,6 +213,8 @@
 else:
     build_libtorrent = False
 
+build_libtorrent = False
+
 if build_libtorrent:
     got_libtorrent = False
     if not os.path.exists("libtorrent"):
@@ -487,31 +488,8 @@
 
 # Data files to be installed to the system
 _data_files = [
-    ('share/icons/scalable/apps', ['deluge/data/icons/scalable/apps/deluge.svg']),
-    ('share/icons/hicolor/128x128/apps', ['deluge/data/icons/hicolor/128x128/apps/deluge.png']),
-    ('share/icons/hicolor/16x16/apps', ['deluge/data/icons/hicolor/16x16/apps/deluge.png']),
-    ('share/icons/hicolor/192x192/apps', ['deluge/data/icons/hicolor/192x192/apps/deluge.png']),
-    ('share/icons/hicolor/22x22/apps', ['deluge/data/icons/hicolor/22x22/apps/deluge.png']),
-    ('share/icons/hicolor/24x24/apps', ['deluge/data/icons/hicolor/24x24/apps/deluge.png']),
-    ('share/icons/hicolor/256x256/apps', ['deluge/data/icons/hicolor/256x256/apps/deluge.png']),
-    ('share/icons/hicolor/32x32/apps', ['deluge/data/icons/hicolor/32x32/apps/deluge.png']),
-    ('share/icons/hicolor/36x36/apps', ['deluge/data/icons/hicolor/36x36/apps/deluge.png']),
-    ('share/icons/hicolor/48x48/apps', ['deluge/data/icons/hicolor/48x48/apps/deluge.png']),
-    ('share/icons/hicolor/64x64/apps', ['deluge/data/icons/hicolor/64x64/apps/deluge.png']),
-    ('share/icons/hicolor/72x72/apps', ['deluge/data/icons/hicolor/72x72/apps/deluge.png']),
-    ('share/icons/hicolor/96x96/apps', ['deluge/data/icons/hicolor/96x96/apps/deluge.png']),
-    ('share/pixmaps', ['deluge/data/pixmaps/deluge.png', 'deluge/data/pixmaps/deluge.xpm']),
-    ('share/man/man1', [
-        'docs/man/deluge.1',
-        'docs/man/deluged.1',
-        'docs/man/deluge-gtk.1',
-        'docs/man/deluge-web.1',
-        'docs/man/deluge-console.1'])
 ]
 
-if not windows_check() and os.path.exists(desktop_data):
-    _data_files.append(('share/applications', [desktop_data]))
-
 entry_points = {
     "console_scripts": [
         "deluge-console = deluge.ui.console:start",
