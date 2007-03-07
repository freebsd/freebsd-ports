--- src/delugegtk.py.orig	Tue Mar  6 20:46:00 2007
+++ src/delugegtk.py	Tue Mar  6 22:42:58 2007
@@ -33,9 +33,9 @@
 	def __init__(self):
 		APP = 'deluge'
 		DIR = os.path.join(dcommon.INSTALL_PREFIX, 'share', 'locale')
-		locale.setlocale(locale.LC_ALL, '')
-		locale.bindtextdomain(APP, DIR)
-		locale.textdomain(APP)
+#		locale.setlocale(locale.LC_ALL, '')
+#		locale.bindtextdomain(APP, DIR)
+#		locale.textdomain(APP)
 		gettext.bindtextdomain(APP, DIR)
 		gettext.textdomain(APP)
 		gettext.install(APP, DIR)
