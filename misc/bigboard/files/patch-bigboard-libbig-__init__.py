--- bigboard/libbig/__init__.py	2008-03-25 20:09:55.000000000 +0530
+++ bigboard/libbig/__init__.py.new	2008-05-28 12:49:50.000000000 +0530
@@ -21,7 +21,7 @@
 
 def get_xdg_datadirs():
     result = []
-    default = '/usr/share'
+    default = '%%LOCALBASE%%/share'
     try:
         for x in os.environ['XDG_DATA_DIRS'].split(':'):
             result.append(x)
