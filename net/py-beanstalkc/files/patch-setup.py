--- ./setup.py.orig	2014-03-08 14:16:00.573786621 +1100
+++ ./setup.py	2014-03-08 14:16:32.606016182 +1100
@@ -29,4 +29,5 @@
         'Operating System :: OS Independent',
         'Topic :: Software Development :: Libraries :: Python Modules',
     ],
+    test_suite = 'nose.collector',
 )
