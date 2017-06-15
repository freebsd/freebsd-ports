--- setup.py.orig	2017-01-04 05:33:56 UTC
+++ setup.py
@@ -270,5 +270,6 @@ setup(
         'Topic :: Software Development :: Libraries :: Python Modules',
         'Topic :: Text Processing :: Filters',
         'Topic :: Text Processing :: Markup :: HTML'
-    ]
+    ],
+    test_suite='nose.collector',
 )
