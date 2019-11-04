--- test/testspf.py.orig	2019-08-31 02:49:19 UTC
+++ test/testspf.py
@@ -237,9 +237,9 @@ def docsuite():
 
 def suite(skipdoc=False): 
   suite = docsuite()
-  suite.addTest(makeSuite('test.yml'))
-  suite.addTest(makeSuite('rfc7208-tests.yml'))
-  suite.addTest(makeSuite('rfc4408-tests.yml'))
+  suite.addTest(makeSuite('test/test.yml'))
+  suite.addTest(makeSuite('test/rfc7208-tests.yml'))
+  suite.addTest(makeSuite('test/rfc4408-tests.yml'))
   return suite
 
 if __name__ == '__main__':
@@ -255,9 +255,9 @@ if __name__ == '__main__':
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
@@ -266,7 +266,7 @@ if __name__ == '__main__':
       tc.addTest(SPFTestCase(t2[i]))
   if not tc:
     # load zonedata for doctests
-    with open('doctest.yml','rb') as fp:
+    with open('test/doctest.yml','rb') as fp:
       zonedata = loadZone(next(yaml.safe_load_all(fp)))
     if doctest:
       tc = docsuite()   # doctests only
