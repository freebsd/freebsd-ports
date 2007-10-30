--- src/__init__.py.orig	2007-10-30 00:15:34.000000000 -0500
+++ src/__init__.py	2007-10-30 00:16:07.000000000 -0500
@@ -37,15 +37,15 @@
 
 APP = 'deluge'
 DIR = os.path.join(common.INSTALL_PREFIX, 'share', 'locale')
-if not common.windows_check(): 
-    locale.setlocale(locale.LC_MESSAGES, '')
-    locale.bindtextdomain(APP, DIR)
-    locale.textdomain(APP)
-else:
-    import gtk.glade
-    locale.setlocale(locale.LC_ALL, '')
-    gtk.glade.bindtextdomain(APP,DIR)
-    gtk.glade.textdomain(APP)
+#if not common.windows_check(): 
+#    locale.setlocale(locale.LC_MESSAGES, '')
+#    locale.bindtextdomain(APP, DIR)
+#    locale.textdomain(APP)
+#else:
+#    import gtk.glade
+#    locale.setlocale(locale.LC_ALL, '')
+#    gtk.glade.bindtextdomain(APP,DIR)
+#    gtk.glade.textdomain(APP)
 gettext.bindtextdomain(APP, DIR)
 gettext.textdomain(APP)
 gettext.install(APP, DIR)
