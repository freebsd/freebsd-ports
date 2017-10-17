--- test/test_scandir.py.orig	2017-09-29 12:38:51 UTC
+++ test/test_scandir.py
@@ -14,6 +14,9 @@ try:
 except ImportError:
     has_scandir = False
 
+reload(sys)
+sys.setdefaultencoding('utf8')
+
 FILE_ATTRIBUTE_DIRECTORY = 16
 
 TEST_PATH = os.path.abspath(os.path.join(os.path.dirname(__file__), 'testdir'))
@@ -48,24 +51,24 @@ def create_file(path, contents='1234'):
 def setup_main():
     join = os.path.join
 
-    os.mkdir(TEST_PATH)
-    os.mkdir(join(TEST_PATH, 'subdir'))
+    os.makedirs(TEST_PATH)
+    os.makedirs(join(TEST_PATH, 'subdir'))
     create_file(join(TEST_PATH, 'file1.txt'))
     create_file(join(TEST_PATH, 'file2.txt'), contents='12345678')
 
-    os.mkdir(join(TEST_PATH, 'subdir', 'unidir\u018F'))
+    os.makedirs(join(TEST_PATH, 'subdir', u'unidir\u018F'))
     create_file(join(TEST_PATH, 'subdir', 'file1.txt'))
-    create_file(join(TEST_PATH, 'subdir', 'unicod\u018F.txt'))
+    create_file(join(TEST_PATH, 'subdir', u'unicod\u018F.txt'))
 
-    create_file(join(TEST_PATH, 'subdir', 'unidir\u018F', 'file1.txt'))
+    create_file(join(TEST_PATH, 'subdir', u'unidir\u018F', 'file1.txt'))
 
-    os.mkdir(join(TEST_PATH, 'linkdir'))
+    os.makedirs(join(TEST_PATH, 'linkdir'))
 
 
 def setup_symlinks():
     join = os.path.join
 
-    os.mkdir(join(TEST_PATH, 'linkdir', 'linksubdir'))
+    os.makedirs(join(TEST_PATH, 'linkdir', 'linksubdir'))
     create_file(join(TEST_PATH, 'linkdir', 'file1.txt'))
 
     os.symlink(os.path.abspath(join(TEST_PATH, 'linkdir', 'file1.txt')),
@@ -217,7 +220,7 @@ class TestMixin(object):
         self.assertTrue(isinstance(entry.path, bytes))
 
         # b'unicod?.txt' on Windows, b'unicod\xc6\x8f.txt' (UTF-8) or similar on POSIX
-        entry_name = 'unicod\u018f.txt'.encode(sys.getfilesystemencoding(), 'replace')
+        entry_name = u'unicod\u018f.txt'.encode(sys.getfilesystemencoding(), 'replace')
         self.assertEqual(entry.name, entry_name)
         self.assertEqual(entry.path, os.path.join(path, entry_name))
 
@@ -234,12 +237,12 @@ class TestMixin(object):
         self.assertTrue(isinstance(entry.name, str))
         self.assertTrue(isinstance(entry.path, str))
 
-        entry_name = 'unicod\u018f.txt'
+        entry_name = u'unicod\u018f.txt'
         self.assertEqual(entry.name, entry_name)
-        self.assertEqual(entry.path, os.path.join(path, 'unicod\u018f.txt'))
+        self.assertEqual(entry.path, os.path.join(path, u'unicod\u018f.txt'))
 
         # Check that it handles unicode input properly
-        path = os.path.join(TEST_PATH, 'subdir', 'unidir\u018f')
+        path = os.path.join(TEST_PATH, 'subdir', u'unidir\u018f')
         self.assertTrue(isinstance(path, str))
         entries = list(self.scandir_func(path))
         self.assertEqual(len(entries), 1)
