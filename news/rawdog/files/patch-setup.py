--- ./setup.py.orig	2013-10-17 15:43:03.702103811 +0100
+++ ./setup.py	2013-10-17 15:43:13.421556778 +0100
@@ -14,7 +14,7 @@
 	author_email = "ats@offog.org",
 	url = "http://offog.org/code/rawdog/",
 	scripts = ['rawdog'],
-	data_files = [('share/man/man1', ['rawdog.1'])],
+	data_files = [('man/man1', ['rawdog.1'])],
 	packages = ['rawdoglib'],
 	classifiers = [
 		"Development Status :: 5 - Production/Stable",
