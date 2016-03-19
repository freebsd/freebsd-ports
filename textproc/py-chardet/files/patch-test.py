--- test.py.orig	2014-10-07 15:03:14 UTC
+++ test.py
@@ -36,11 +36,8 @@ class TestCase(unittest.TestCase):
 
 def main():
     suite = unittest.TestSuite()
-    if len(sys.argv) > 1:
-        base_path = sys.argv[1]
-    else:
-        base_path = os.path.join(
-            os.path.dirname(os.path.abspath(__file__)), 'tests')
+    base_path = os.path.join(
+        os.path.dirname(os.path.abspath(__file__)), 'tests')
     for encoding in os.listdir(base_path):
         path = os.path.join(base_path, encoding)
         if not os.path.isdir(path):
