--- setup.py.orig	2014-08-29 13:05:09.876530572 -0300
+++ setup.py	2014-08-29 13:10:31.034824736 -0300
@@ -379,7 +379,9 @@
     for subdir in ['docs', 'share']:
         docwalk = os.walk(subdir)
         for docs in docwalk:
-            docfiles.append(listfiles(docs[0]))
+            files = listfiles(docs[0])
+            if files[1]:
+                docfiles.append(files)
         datafiles += docfiles
     return datafiles
 
