--- ./setup.py.orig	2013-01-11 11:56:38.000000000 +1100
+++ ./setup.py	2013-06-16 20:20:50.928843954 +1000
@@ -32,7 +32,7 @@
 KEYWORDS = "feed atom rss".split(' ')
 VERSION = '1.5'
 
-TEST_SUITE = 'tests'
+TEST_SUITE = 'tests_feedgenerator'
 
 REQUIRES = ['pytz', 'six']
 
@@ -52,4 +52,5 @@
     keywords=KEYWORDS,
     url=URL,
     classifiers=CLASSIFIERS,
+    zip_safe=False,
 )
