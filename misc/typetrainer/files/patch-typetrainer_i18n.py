--- typetrainer/i18n.py.orig	2011-02-12 17:43:17.000000000 +0300
+++ typetrainer/i18n.py	2011-02-12 17:43:26.000000000 +0300
@@ -7,7 +7,7 @@
 
 if gettext.find(APP, DIR):
     locale.setlocale(locale.LC_ALL, '')
-    locale.bindtextdomain(APP, DIR)
+    #locale.bindtextdomain(APP, DIR)
     gettext.bindtextdomain(APP, DIR)
     gettext.textdomain(APP)
 
