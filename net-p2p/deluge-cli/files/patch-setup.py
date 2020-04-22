--- setup.py.orig	2019-06-08 20:57:25 UTC
+++ setup.py
@@ -466,16 +466,6 @@ if not windows_check() and not osx_check():
                 ['deluge/ui/data/icons/hicolor/scalable/apps/deluge.svg'],
             ),
             ('share/pixmaps', ['deluge/ui/data/pixmaps/deluge.png']),
-            (
-                'share/man/man1',
-                [
-                    'docs/man/deluge.1',
-                    'docs/man/deluged.1',
-                    'docs/man/deluge-gtk.1',
-                    'docs/man/deluge-web.1',
-                    'docs/man/deluge-console.1',
-                ],
-            ),
         ]
     )
     if os.path.isfile(desktop_data):
