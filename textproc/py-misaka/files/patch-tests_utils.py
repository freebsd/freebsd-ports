# textproc/html5-tidy doesn't provide a 'tidy' binary
# and BINARY_ALIAS doesn't work at test: time
# TODO: Ask upstream to support a TIDY_BIN variable

--- tests/utils.py.orig	2019-09-06 11:18:46 UTC
+++ tests/utils.py
@@ -5,7 +5,7 @@ from subprocess import Popen, PIPE, STDOUT
 
 def clean_html(dirty_html):
     input_html = dirty_html.encode('utf-8')
-    p = Popen(['tidy', '--show-body-only', '1', '--quiet', '1', '--show-warnings', '0', '-utf8'],
+    p = Popen(['tidy5', '--show-body-only', '1', '--quiet', '1', '--show-warnings', '0', '-utf8'],
         stdout=PIPE, stdin=PIPE, stderr=STDOUT)
     stdout, stderr = p.communicate(input=input_html)
 
