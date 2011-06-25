--- turpial/ui/gtk/about.py.orig	2011-01-22 22:05:08.000000000 +0100
+++ turpial/ui/gtk/about.py	2011-02-18 23:35:39.000000000 +0100
@@ -22,8 +22,8 @@
         about.set_website('http://turpial.org.ve')
         
         try:
-            path = os.path.realpath(os.path.join(os.path.dirname(__file__), 
-                '..', '..', '..', 'COPYING'))
+            path = os.path.realpath(os.path.join('%%PREFIX%%', 'share', 'doc', 
+                'turpial', 'COPYING'))
             lic = file(path, 'r')
             license = lic.read()
             lic.close()
@@ -39,8 +39,8 @@
         about.set_license(license)
         authors = []
         try:
-            path = os.path.realpath(os.path.join(os.path.dirname(__file__), 
-                '..', '..', '..', 'AUTHORS'))
+            path = os.path.realpath(os.path.join('%%PREFIX%%', 'share', 'doc', 
+                'turpial', 'AUTHORS'))
             f = file(path, 'r')
             for line in f:
                 authors.append(line.strip('\n'))
@@ -51,8 +51,8 @@
         
         translators = ''
         try:
-            path = os.path.realpath(os.path.join(os.path.dirname(__file__), 
-                '..', '..', '..', 'TRANSLATORS'))
+            path = os.path.realpath(os.path.join('%%PREFIX%%', 'share', 'doc', 
+                'turpial', 'TRANSLATORS'))
             f = file(path, 'r')
             translators = f.read()
             f.close()
