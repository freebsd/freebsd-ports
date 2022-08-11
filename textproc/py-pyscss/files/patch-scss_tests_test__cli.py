https://github.com/Kronuz/pyScss/pull/425

--- scss/tests/test_cli.py.orig	2020-03-26 15:04:27 UTC
+++ scss/tests/test_cli.py
@@ -1,4 +1,5 @@
 """Test the command-line tool from the outside."""
+import sys
 from subprocess import PIPE, Popen
 
 # TODO: this needs way, way, way, way more tests
@@ -6,7 +7,7 @@ from subprocess import PIPE, Popen
 
 def test_stdio():
     proc = Popen(
-        ['python', '-m', 'scss.tool', '-C'],
+        [sys.executable, '-m', 'scss.tool', '-C'],
         stdin=PIPE,
         stdout=PIPE,
         # this automatically handles encoding/decoding on py3
