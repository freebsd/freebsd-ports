--- ./heybuddy.py.orig	2011-10-15 07:34:58.000000000 -0400
+++ ./heybuddy.py	2011-10-15 07:38:40.000000000 -0400
@@ -21,9 +21,7 @@
 import sys, os
 import gettext
 import webbrowser
-locale_dir = os.path.join(
-	os.path.dirname( os.path.realpath(__file__) ),
-	'locales')
+locale_dir = '%%PREFIX%%/share/locale'
 
 gettext.bindtextdomain('heybuddy', locale_dir)
 gettext.textdomain('heybuddy')
@@ -107,7 +105,7 @@
 		self.last_get_statuses = 0
 		#what are the assets?
 		asset_dir = 'assets'
-		heybuddy_dir = os.path.dirname( os.path.realpath( __file__ ) )
+		heybuddy_dir = '%%DATADIR%%'
 		self.readme_file = os.path.join(heybuddy_dir,'README.txt')
 		self.standard_icon_path = os.path.join(heybuddy_dir,asset_dir,'icon.png')
 		self.direct_icon_path = os.path.join(heybuddy_dir,asset_dir,'direct_icon.png')
