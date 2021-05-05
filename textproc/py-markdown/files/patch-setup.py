--- setup.py.orig	2021-02-24 19:57:42 UTC
+++ setup.py
@@ -129,5 +129,6 @@ setup(
         'Topic :: Text Processing :: Filters',
         'Topic :: Text Processing :: Markup :: HTML',
         'Topic :: Text Processing :: Markup :: Markdown'
-    ]
+    ],
+    test_suite='nose.collector',
 )
