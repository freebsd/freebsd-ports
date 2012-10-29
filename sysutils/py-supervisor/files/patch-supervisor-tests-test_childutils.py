--- supervisor/tests/test_childutils.py
+++ supervisor/tests/test_childutils.py
@@ -41,7 +41,7 @@ class ChildUtilsTests(unittest.TestCase):
 
     def test_get_asctime(self):
         from supervisor.childutils import get_asctime
-        timestamp = time.mktime((2009, 1, 18, 22, 14, 7, 0, 0, 0))
+        timestamp = time.mktime((2009, 1, 18, 22, 14, 7, 0, 0, -1))
         result = get_asctime(timestamp)
         self.assertEqual(result, '2009-01-18 22:14:07,000')

