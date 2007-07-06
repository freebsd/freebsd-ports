--- src/interface.py.orig	Thu Jul  5 22:48:09 2007
+++ src/interface.py	Thu Jul  5 22:48:21 2007
@@ -43,9 +43,9 @@
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
