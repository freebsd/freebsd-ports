--- setup.py.orig	Wed Jul 12 09:55:04 2006
+++ setup.py	Wed Jul 12 20:44:42 2006
@@ -13,10 +13,11 @@
       packages = ['sabnzbd', 'sabnzbd.utils', 'sabnzbd.utils.multiauth'],
       platforms = ['posix'],
       license = 'GNU General Public License 2 (GPL2)',
-      data_files = [('share/doc/SABnzbd-' + sabnzbd.__version__,
-                     ['SABnzbd.ini.sample', 'README.txt', 'LICENSE.txt',
-                      'TODO.txt', 'CHANGELOG.txt', 'UPGRADE.txt']),
-                    ('share/SABnzbd-' + sabnzbd.__version__ + '/templates',
+      data_files = [('share/doc/%%PORTNAME%%',
+                             ['README.txt', 'LICENSE.txt',
+                              'TODO.txt', 'CHANGELOG.txt', 'UPGRADE.txt']),
+                    ('share/%%PORTNAME%%',['SABnzbd.ini.sample']),
+                    ('share/%%PORTNAME%%' + '/templates',
                              ['templates/default.css', 'templates/history.tmpl',
                               'templates/main.tmpl',
 			      'templates/connection_info.tmpl',
@@ -30,5 +31,5 @@
                               'templates/config_scheduling.tmpl',
                               'templates/config_rss.tmpl',
                               'templates/static/placeholder.txt']),
-                    ('share/SABnzbd-' + sabnzbd.__version__ + '/templates/static',
+                    ('share/%%PORTNAME%%/templates/static',
                               ['templates/static/placeholder.txt'])])
