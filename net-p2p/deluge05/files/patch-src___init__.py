--- src/__init__.py.orig	2007-08-05 13:08:25.000000000 -0500
+++ src/__init__.py	2007-08-05 13:08:40.000000000 -0500
@@ -6,9 +6,9 @@
 
 APP = 'deluge'
 DIR = os.path.join(INSTALL_PREFIX, 'share', 'locale')
-locale.setlocale(locale.LC_ALL, '')
-locale.bindtextdomain(APP, DIR)
-locale.textdomain(APP)
+#locale.setlocale(locale.LC_ALL, '')
+#locale.bindtextdomain(APP, DIR)
+#locale.textdomain(APP)
 gettext.bindtextdomain(APP, DIR)
 gettext.textdomain(APP)
 gettext.install(APP, DIR)
