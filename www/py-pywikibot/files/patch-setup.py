--- setup.py.orig	2018-03-05 08:16:49 UTC
+++ setup.py
@@ -213,14 +213,14 @@ from setuptools import setup, find_packa
 name = 'pywikibot'
 version = '3.0'
 
-try:
-    import subprocess
-    date = subprocess.check_output(['git', 'log', '-1', '--format=%ci']).strip()
-    date = date.decode().split(' ')[0].replace('-', '')
-    version = version + "." + date
-except Exception as e:
-    print(e)
-    version = version + "-dev"
+#try:
+#    import subprocess
+#    date = subprocess.check_output(['git', 'log', '-1', '--format=%ci']).strip()
+#    date = date.decode().split(' ')[0].replace('-', '')
+#    version = version + "." + date
+#except Exception as e:
+#    print(e)
+#    version = version + "-dev"
 
 
 def read_desc(filename):
