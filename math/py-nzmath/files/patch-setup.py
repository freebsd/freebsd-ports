--- setup.py.orig	2011-06-03 06:35:10.000000000 +0800
+++ setup.py	2011-06-03 06:35:41.000000000 +0800
@@ -21,9 +21,9 @@
 
     packages=['nzmath', 'nzmath.config', 'nzmath.factor', 'nzmath.poly', 'nzmath.plugin', 'nzmath.plugin.math'],
 
-    data_files=[
-        (data_prefix, ['data/discriminant.csv']),
-        (doc_prefix + 'manual',
-            glob.glob('manual/*.pdf')),
-    ]
+#    data_files=[
+#        (data_prefix, ['data/discriminant.csv']),
+#        (doc_prefix + 'manual',
+#            glob.glob('manual/*.pdf')),
+#    ]
 )
