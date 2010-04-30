--- ./setup.py.orig	2010-04-30 10:09:50.411058590 -0400
+++ ./setup.py	2010-04-30 10:10:32.801862294 -0400
@@ -26,6 +26,7 @@
     return (name.startswith('.') or
             name.startswith('#') or
             name.endswith('.pickle') or
+            name.endswith('.orig') or
             name == 'CVS')
 
 def isgood(name):
