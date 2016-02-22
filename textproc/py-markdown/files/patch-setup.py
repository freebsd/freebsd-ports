--- setup.py.orig	2016-02-20 06:59:25 UTC
+++ setup.py
@@ -268,5 +268,6 @@ setup(
         'Topic :: Software Development :: Libraries :: Python Modules',
         'Topic :: Text Processing :: Filters',
         'Topic :: Text Processing :: Markup :: HTML'
-    ]
+    ],
+    test_suite='nose.collector',
 )
