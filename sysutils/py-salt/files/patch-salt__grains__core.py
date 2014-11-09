--- ./salt/grains/core.py.orig  2014-11-03 12:38:21.000000000 -0700
+++ ./salt/grains/core.py       2014-11-04 13:34:47.769728417 -0700
@@ -1320,7 +1320,7 @@
     '''
     # Provides:
     #   path
-    return {'path': os.environ['PATH'].strip()}
+    return {'path': os.environ['PATH'].strip() + ':/usr/local/bin:/usr/local/sbin'}
 
 
 def pythonversion():
