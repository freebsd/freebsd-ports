--- src/plugins/plugins_i18n.py.orig	2012-03-18 15:26:00.000000000 +0400
+++ src/plugins/plugins_i18n.py	2012-03-21 08:21:52.000000000 +0400
@@ -29,7 +29,6 @@
 
 if os.name != 'nt':
     locale.setlocale(locale.LC_ALL, '')
-    locale.bindtextdomain(APP, plugins_locale_dir)
     gettext.bindtextdomain(APP, plugins_locale_dir)
     gettext.textdomain(APP)
 
