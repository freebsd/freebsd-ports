--- bindings/python/setup.py.orig	2020-03-23 14:32:28 UTC
+++ bindings/python/setup.py
@@ -86,7 +86,6 @@ setup(
                   'MythTV/wikiscripts', 'MythTV/utility',
 				  'MythTV/services_api'],
         package_dir={'MythTV/tmdb3':'./tmdb3/tmdb3'},
-        data_files=[('MythTV/ttvdb/XSLT', glob.glob('MythTV/ttvdb/XSLT/*'))],
         url=['http://www.mythtv.org/'],
         scripts=SCRIPTS,
         requires=['MySQLdb','lxml'],
