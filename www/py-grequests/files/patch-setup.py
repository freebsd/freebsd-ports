# Support test command w/ tests_require & test_suite
# https://github.com/kennethreitz/grequests/pull/47

--- ./setup.py.orig	2014-02-16 17:35:13.772145487 +1100
+++ ./setup.py	2014-02-16 17:36:15.191123632 +1100
@@ -56,5 +56,7 @@
         'Programming Language :: Python',
         'Topic :: Internet :: WWW/HTTP :: Dynamic Content',
         'Topic :: Software Development :: Libraries :: Python Modules'
-    ]
+    ],
+    tests_require = ['nose'],
+    test_suite = 'nose.collector',
 )
