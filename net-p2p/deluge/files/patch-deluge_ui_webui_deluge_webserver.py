--- deluge/ui/webui/deluge_webserver.py.orig	2009-01-17 11:35:46.000000000 -0600
+++ deluge/ui/webui/deluge_webserver.py	2009-01-17 11:35:59.000000000 -0600
@@ -35,11 +35,11 @@
 
 # Initialize gettext
 try:
-    locale.setlocale(locale.LC_ALL, '')
-    if hasattr(locale, "bindtextdomain"):
-        locale.bindtextdomain("deluge", pkg_resources.resource_filename("deluge", "i18n"))
-    if hasattr(locale, "textdomain"):
-        locale.textdomain("deluge")
+#    locale.setlocale(locale.LC_ALL, '')
+#    if hasattr(locale, "bindtextdomain"):
+#        locale.bindtextdomain("deluge", pkg_resources.resource_filename("deluge", "i18n"))
+#    if hasattr(locale, "textdomain"):
+#        locale.textdomain("deluge")
     gettext.bindtextdomain("deluge", pkg_resources.resource_filename("deluge", "i18n"))
     gettext.textdomain("deluge")
     gettext.install("deluge", pkg_resources.resource_filename("deluge", "i18n"))
