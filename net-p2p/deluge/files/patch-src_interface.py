--- src/interface.py.orig	Sat Jun  9 12:20:35 2007
+++ src/interface.py	Sat Jun  9 12:20:54 2007
@@ -75,9 +75,9 @@
 	def __init__(self):
 		APP = 'deluge'
 		DIR = os.path.join(common.INSTALL_PREFIX, 'share', 'locale')
-		locale.setlocale(locale.LC_ALL, '')
-		locale.bindtextdomain(APP, DIR)
-		locale.textdomain(APP)
+#		locale.setlocale(locale.LC_ALL, '')
+#		locale.bindtextdomain(APP, DIR)
+#		locale.textdomain(APP)
 		gettext.bindtextdomain(APP, DIR)
 		gettext.textdomain(APP)
 		gettext.install(APP, DIR)
