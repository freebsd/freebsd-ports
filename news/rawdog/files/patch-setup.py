--- setup.py.orig	2016-10-12 12:42:34 UTC
+++ setup.py
@@ -14,7 +14,7 @@ setup(name="rawdog",
 	author_email="ats@offog.org",
 	url="http://offog.org/code/rawdog/",
 	scripts=['rawdog'],
-	data_files=[('share/man/man1', ['rawdog.1'])],
+	data_files=[('man/man1', ['rawdog.1'])],
 	packages=['rawdoglib'],
 	classifiers=[
 		"Development Status :: 5 - Production/Stable",
