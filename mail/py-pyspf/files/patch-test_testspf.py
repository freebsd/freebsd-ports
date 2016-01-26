--- test/testspf.py.orig	2015-01-12 22:47:56 UTC
+++ test/testspf.py
@@ -221,9 +221,9 @@ def makeSuite(filename):
 
 def suite(): 
   suite = unittest.makeSuite(SPFTestCases,'test')
-  suite.addTest(makeSuite('test.yml'))
-  suite.addTest(makeSuite('rfc7208-tests.yml'))
-  suite.addTest(makeSuite('rfc4408-tests.yml'))
+  suite.addTest(makeSuite('test/test.yml'))
+  suite.addTest(makeSuite('test/rfc7208-tests.yml'))
+  suite.addTest(makeSuite('test/rfc4408-tests.yml'))
   import doctest
   suite.addTest(doctest.DocTestSuite(spf))
   return suite
@@ -237,9 +237,9 @@ if __name__ == '__main__':
     # a specific test selected by id from YAML files
     if not tc:
       tc = unittest.TestSuite()
-      t0 = loadYAML('rfc7208-tests.yml')
-      t1 = loadYAML('rfc4408-tests.yml')
-      t2 = loadYAML('test.yml')
+      t0 = loadYAML('test/rfc7208-tests.yml')
+      t1 = loadYAML('test/rfc4408-tests.yml')
+      t2 = loadYAML('test/test.yml')
     if i in t0:
       tc.addTest(SPFTestCase(t0[i]))
     if i in t1:
@@ -248,7 +248,7 @@ if __name__ == '__main__':
       tc.addTest(SPFTestCase(t2[i]))
   if not tc:
     # load zonedata for doctests
-    fp = open('doctest.yml','rb')
+    fp = open('test/doctest.yml','rb')
     try:
       zonedata = loadZone(next(yaml.safe_load_all(fp)))
     finally: fp.close()
