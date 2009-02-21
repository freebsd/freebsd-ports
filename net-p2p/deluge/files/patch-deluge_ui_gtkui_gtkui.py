--- deluge/ui/gtkui/gtkui.py.orig	2009-02-21 16:50:22.000000000 -0600
+++ deluge/ui/gtkui/gtkui.py	2009-02-21 16:50:24.000000000 -0600
@@ -119,10 +119,10 @@
 
         # Initialize gettext
         try:
-            if hasattr(locale, "bindtextdomain"):
-                locale.bindtextdomain("deluge", pkg_resources.resource_filename("deluge", "i18n"))
-            if hasattr(locale, "textdomain"):
-                locale.textdomain("deluge")
+#            if hasattr(locale, "bindtextdomain"):
+#                locale.bindtextdomain("deluge", pkg_resources.resource_filename("deluge", "i18n"))
+#            if hasattr(locale, "textdomain"):
+#                locale.textdomain("deluge")
             gettext.bindtextdomain("deluge", pkg_resources.resource_filename("deluge", "i18n"))
             gettext.textdomain("deluge")
             gettext.install("deluge", pkg_resources.resource_filename("deluge", "i18n"))
