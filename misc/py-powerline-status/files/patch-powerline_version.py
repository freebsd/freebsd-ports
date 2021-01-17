--- powerline/version.py.orig	2021-01-17 14:39:35 UTC
+++ powerline/version.py
@@ -7,9 +7,5 @@ from traceback import print_exc
 __version__ = "2.8.1"
 
 def get_version():
-	try:
-		return __version__ + '.dev9999+git.' + str(subprocess.check_output(['git', 'rev-parse', 'HEAD']).strip())
-	except Exception:
-		print_exc()
-		return __version__
+	return __version__
 
