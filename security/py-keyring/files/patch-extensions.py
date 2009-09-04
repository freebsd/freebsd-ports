--- extensions.py.orig	2009-08-21 09:34:01.000000000 -0700
+++ extensions.py	2009-09-03 15:43:41.224189815 -0700
@@ -42,9 +42,9 @@
 
     keywords.setdefault('libraries', []).append('kdeui')
     libs = commands.getoutput("kde4-config --path lib").split(':')
-    if len(libs) == 0:
-        libs = commands.getoutput("kde-config --path lib").split(':')
     keywords.setdefault('library_dirs', []).extend(libs)
+    includes = commands.getoutput("kde4-config --install include").split(':')
+    keywords.setdefault('include_dirs', []).extend(includes)
     return keywords
 
 def get_extensions():
