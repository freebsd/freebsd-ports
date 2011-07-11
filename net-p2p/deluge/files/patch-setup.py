--- ./setup.py.orig	2011-07-08 18:15:27.000000000 -0400
+++ ./setup.py	2011-07-08 18:16:21.000000000 -0400
@@ -213,6 +213,7 @@
     build_libtorrent = True
 else:
     build_libtorrent = False
+build_libtorrent = False
 
 if build_libtorrent:
     got_libtorrent = False
@@ -401,27 +402,6 @@
 
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
-    ('share/applications', ['deluge/data/share/applications/deluge.desktop']),
-    ('share/pixmaps', ['deluge/data/pixmaps/deluge.png', 'deluge/data/pixmaps/deluge.xpm']),
-    ('share/man/man1', [
-        'docs/man/deluge.1',
-        'docs/man/deluged.1',
-        'docs/man/deluge-gtk.1',
-        'docs/man/deluge-web.1',
-        'docs/man/deluge-console.1'])
 ]
 
 entry_points = {
