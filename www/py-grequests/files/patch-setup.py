--- ./setup.py.orig	2013-03-05 10:04:42.000000000 +1100
+++ ./setup.py	2013-04-29 20:25:38.800634016 +1000
@@ -56,5 +56,6 @@
         'Programming Language :: Python',
         'Topic :: Internet :: WWW/HTTP :: Dynamic Content',
         'Topic :: Software Development :: Libraries :: Python Modules'
-    ]
+    ],
+    test_suite='tests'
 )
