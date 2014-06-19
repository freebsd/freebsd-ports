--- setup.py.orig	2014-06-19 18:38:48.000000000 +0200
+++ setup.py	2014-06-19 18:38:59.000000000 +0200
@@ -9,13 +9,13 @@
 
 import os
 data_files=[]
-for (dirpath, dirnames, filenames) in os.walk("doc"):
-    if ".svn" in dirnames:
-        del dirnames[dirnames.index(".svn")]
-    thesedocs = []
-    for fname in filenames:
-        thesedocs.append(os.path.join(dirpath, fname))
-    data_files.append((dirpath, thesedocs))
+#for (dirpath, dirnames, filenames) in os.walk("doc"):
+#    if ".svn" in dirnames:
+#        del dirnames[dirnames.index(".svn")]
+#    thesedocs = []
+#    for fname in filenames:
+#        thesedocs.append(os.path.join(dirpath, fname))
+#    data_files.append((dirpath, thesedocs))
 
 data_files.append((os.path.join('twisted', 'plugins'), [os.path.join('twisted', 'plugins', 'nevow_widget.py')]))
 
