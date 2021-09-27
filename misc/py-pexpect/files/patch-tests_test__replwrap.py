--- tests/test_replwrap.py.orig	2021-09-22 14:15:55 UTC
+++ tests/test_replwrap.py
@@ -24,7 +24,7 @@ class REPLWrapTestCase(unittest.TestCase):
 
     def test_bash(self):
         bash = replwrap.bash()
-        res = bash.run_command("alias")
+        res = bash.run_command("alias xyzzy=true; alias")
         assert 'alias' in res, res
 
         try:
