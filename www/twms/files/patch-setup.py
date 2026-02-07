--- setup.py.orig	2018-05-08 12:10:19 UTC
+++ setup.py
@@ -11,7 +11,7 @@ is_windows = __platform__ in ['Windows']
 __name__ = "twms"
 
 def read(fname):
-    return open(os.path.join(os.path.dirname(__file__), fname)).read()
+    return open(os.path.join(os.path.dirname(__file__), fname), 'rb').read().decode('utf-8')
 
 def glob(fname):
     return abs_glob(os.path.join(os.path.dirname(__file__), fname))
@@ -25,7 +25,7 @@ def man_files(pattern):
 
 def config_files():
     if not is_windows:
-        return [(os.path.join('/etc', __name__), [os.path.join('twms', 'twms.conf')])]
+        return [(os.path.join('etc', __name__), [os.path.join('twms', 'twms.conf')])]
     else:
         return []
 
