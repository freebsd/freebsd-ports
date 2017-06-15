--- progressbar/widgets.py.orig	2011-05-15 23:08:48 UTC
+++ progressbar/widgets.py
@@ -84,8 +84,8 @@ class Timer(Widget):
     __slots__ = ('format',)
     TIME_SENSITIVE = True
 
-    def __init__(self, format='Elapsed Time: %s'):
-        self.format = format
+    def __init__(self, _format='Elapsed Time: %s'):
+        self.format = _format
 
     @staticmethod
     def format_time(seconds):
@@ -121,7 +121,7 @@ class ETA(Timer):
 class FileTransferSpeed(Widget):
     'Widget for showing the transfer speed (useful for file transfers).'
 
-    format = '%6.2f %s%s/s'
+    _format = '%6.2f %s%s/s'
     prefixes = ' kMGTPEZY'
     __slots__ = ('unit', 'format')
 
@@ -170,8 +170,8 @@ class Counter(Widget):
 
     __slots__ = ('format',)
 
-    def __init__(self, format='%d'):
-        self.format = format
+    def __init__(self, _format='%d'):
+        self.format = _format
 
     def update(self, pbar):
         return self.format % pbar.currval
@@ -198,8 +198,8 @@ class FormatLabel(Timer):
     }
 
     __slots__ = ('format',)
-    def __init__(self, format):
-        self.format = format
+    def __init__(self, _format):
+        self.format = _format
 
     def update(self, pbar):
         context = {}
