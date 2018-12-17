Equivalent of the commit 162b0c787e2005efebac7beb97d1dd681bb692b7
that fixes https://github.com/retext-project/retext/issues/422

--- setup.py.orig	2017-02-11 15:21:52 UTC
+++ setup.py
@@ -16,6 +16,7 @@ For more details, please go to the `home
 
 import platform
 import re
+import os
 import sys
 from os.path import join
 from distutils import log
@@ -35,9 +36,10 @@ if sys.version_info[0] < 3:
 def build_translations():
 	print('running build_translations')
 	error = None
+	environment = dict(os.environ, QT_SELECT='5')
 	for ts_file in glob(join('locale', '*.ts')):
 		try:
-			check_call(('lrelease', ts_file), env={'QT_SELECT': '5'})
+			check_call(('lrelease', ts_file), env=environment)
 		except Exception as e:
 			error = e
 	if error:
