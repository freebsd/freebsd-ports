--- setup.py.bak	Thu Dec  9 18:20:00 2004
+++ setup.py	Thu Dec  9 18:20:12 2004
@@ -10,7 +10,7 @@
 	url = "http://offog.org/code/rawdog.html",
 	license = "GNU GPL v2 or later",
 	scripts = ['rawdog'],
-	data_files = [('share/man/man1', ['rawdog.1'])],
+	data_files = [('man/man1', ['rawdog.1'])],
 	packages = ['rawdoglib'])
 
 
