--- setup.py.orig	2010-09-18 15:31:07.000000000 -0300
+++ setup.py	2010-09-19 23:33:09.000000000 -0300
@@ -211,6 +203,7 @@
     build_libtorrent = True
 else:
     build_libtorrent = False
+build_libtorrent = False
 
 if build_libtorrent:
     got_libtorrent = False
@@ -399,7 +392,7 @@
 
 # Data files to be installed to the system
 _data_files = [
-    ('share/icons/scalable/apps', ['deluge/data/icons/scalable/apps/deluge.svg']),
+    ('share/icons/hicolor/scalable/apps', ['deluge/data/icons/scalable/apps/deluge.svg']),
     ('share/icons/hicolor/128x128/apps', ['deluge/data/icons/hicolor/128x128/apps/deluge.png']),
     ('share/icons/hicolor/16x16/apps', ['deluge/data/icons/hicolor/16x16/apps/deluge.png']),
     ('share/icons/hicolor/192x192/apps', ['deluge/data/icons/hicolor/192x192/apps/deluge.png']),
@@ -413,13 +406,7 @@
     ('share/icons/hicolor/72x72/apps', ['deluge/data/icons/hicolor/72x72/apps/deluge.png']),
     ('share/icons/hicolor/96x96/apps', ['deluge/data/icons/hicolor/96x96/apps/deluge.png']),
     ('share/applications', ['deluge/data/share/applications/deluge.desktop']),
-    ('share/pixmaps', ['deluge/data/pixmaps/deluge.png', 'deluge/data/pixmaps/deluge.xpm']),
-    ('share/man/man1', [
-        'docs/man/deluge.1',
-        'docs/man/deluged.1',
-        'docs/man/deluge-gtk.1',
-        'docs/man/deluge-web.1',
-        'docs/man/deluge-console.1'])
+    ('share/pixmaps', ['deluge/data/pixmaps/deluge.png', 'deluge/data/pixmaps/deluge.xpm'])
 ]
 
 # Main setup
