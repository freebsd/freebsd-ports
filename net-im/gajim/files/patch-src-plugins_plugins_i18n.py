--- src/plugins/plugins_i18n.py.orig	2015-12-28 12:38:51 UTC
+++ src/plugins/plugins_i18n.py
@@ -29,7 +29,6 @@ plugins_locale_dir = os_path.join(gajim.
 
 if os.name != 'nt':
     locale.setlocale(locale.LC_ALL, '')
-    locale.bindtextdomain(APP, plugins_locale_dir)
     gettext.bindtextdomain(APP, plugins_locale_dir)
     gettext.textdomain(APP)
 
