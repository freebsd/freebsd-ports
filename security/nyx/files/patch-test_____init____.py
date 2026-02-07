--- test/__init__.py.orig	2024-11-18 07:14:15 UTC
+++ test/__init__.py
@@ -94,7 +94,7 @@ def render(func, *args, **kwargs):
     nyx.curses.CURSES_SCREEN.erase()
     start_time = time.time()
 
-    func_args = inspect.getargspec(func).args
+    func_args = inspect.getfullargspec(func).args
 
     if func_args[:1] == ['subwindow'] or func_args[:2] == ['self', 'subwindow']:
       def _draw(subwindow):
