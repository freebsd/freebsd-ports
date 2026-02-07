--- setup.py.orig	2016-10-31 20:44:02 UTC
+++ setup.py
@@ -26,6 +26,7 @@ def isbad(name):
     return (name.startswith('.') or
             name.startswith('#') or
             name.endswith('.pickle') or
+            name.endswith('.orig') or
             name == 'CVS')
 
 def isgood(name):
