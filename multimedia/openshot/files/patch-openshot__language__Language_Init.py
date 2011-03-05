--- ./openshot/language/Language_Init.py.orig	2010-09-08 07:17:53.000000000 -0700
+++ ./openshot/language/Language_Init.py	2011-03-04 04:56:22.000000000 -0800
@@ -83,7 +83,7 @@
 		#langs += ["es", "fr"]
 		locale.setlocale(locale.LC_ALL)
 		locale.setlocale(locale.LC_NUMERIC, 'POSIX')
-		locale.bindtextdomain("OpenShot", self.project.LOCALE_DIR)
+		#locale.bindtextdomain("OpenShot", self.project.LOCALE_DIR)
 		
 		gettext.textdomain("OpenShot")
 		gettext.bindtextdomain("OpenShot", self.project.LOCALE_DIR)
@@ -91,4 +91,4 @@
 		gettext.install(domain="OpenShot")
 
 		# This reference is used by other classes to define the _ method 
-		self.lang = gettext.translation("OpenShot", self.project.LOCALE_DIR, languages = langs, fallback = True)
\ No newline at end of file
+		self.lang = gettext.translation("OpenShot", self.project.LOCALE_DIR, languages = langs, fallback = True)
