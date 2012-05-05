--- openshot/language/Language_Init.py.orig	2012-01-02 03:39:04.000000000 +0400
+++ openshot/language/Language_Init.py	2012-03-24 21:08:33.000000000 +0400
@@ -82,8 +82,8 @@
 
 		# Set locale specific settings
 		locale.setlocale(locale.LC_ALL)
-		locale.bindtextdomain("OpenShot", self.project.LOCALE_DIR)
-		locale.bind_textdomain_codeset("OpenShot", "UTF-8")
+#		locale.bindtextdomain("OpenShot", self.project.LOCALE_DIR)
+#		locale.bind_textdomain_codeset("OpenShot", "UTF-8")
 
 		# Set gettext settings
 		gettext.bindtextdomain("OpenShot", self.project.LOCALE_DIR)
