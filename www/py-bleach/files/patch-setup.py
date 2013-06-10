--- ./setup.py.orig	2013-06-10 11:19:04.719234114 +1000
+++ ./setup.py	2013-06-10 11:19:34.305595246 +1000
@@ -23,5 +23,6 @@
         'Operating System :: OS Independent',
         'Programming Language :: Python',
         'Topic :: Software Development :: Libraries :: Python Modules',
-    ]
+    ],
+    test_suite='nose.collector'
 )
