--- ./test/units/TestUtils.py.orig	2014-05-23 16:37:57.000000000 -0400
+++ ./test/units/TestUtils.py	2014-05-31 09:13:44.141967206 -0400
@@ -3,6 +3,7 @@
 import unittest
 import os
 import os.path
+import re
 import tempfile
 import yaml
 import passlib.hash
@@ -511,8 +512,8 @@
         cmd = ansible.utils.make_su_cmd('root', '/bin/sh', '/bin/ls')
         self.assertTrue(isinstance(cmd, tuple))
         self.assertEqual(len(cmd), 3)
-        self.assertTrue(' root /bin/sh' in cmd[0])
-        self.assertTrue(cmd[1] == 'assword: ')
+        self.assertTrue(' root -c "/bin/sh' in cmd[0])
+        self.assertTrue(re.compile(cmd[1]))
         self.assertTrue('echo SUDO-SUCCESS-' in cmd[0] and cmd[2].startswith('SUDO-SUCCESS-'))
 
     def test_to_unicode(self):
