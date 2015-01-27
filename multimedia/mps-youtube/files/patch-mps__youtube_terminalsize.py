--- mps_youtube/terminalsize.py.orig	2015-01-27 17:31:17 UTC
+++ mps_youtube/terminalsize.py
@@ -17,13 +17,13 @@ def get_terminal_size():
      http://stackoverflow.com/questions/566746/how-to-get-console-window-width-in-python
     """
     current_os = platform.system()
-    tuple_xy = None, None
+    tuple_xy = None
     if current_os == 'Windows':
         tuple_xy = _get_terminal_size_windows()
         if tuple_xy is None:
             tuple_xy = _get_terminal_size_tput()
             # needed for window's python in cygwin's xterm!
-    if current_os in ['Linux', 'Darwin'] or current_os.startswith('CYGWIN'):
+    else:
         tuple_xy = _get_terminal_size_linux()
     if tuple_xy is None:
         tuple_xy = (80, 25)      # default value
@@ -83,7 +83,7 @@ def _get_terminal_size_linux():
         try:
             cr = (os.environ['LINES'], os.environ['COLUMNS'])
         except:
-            return None, None
+            return
     return int(cr[1]), int(cr[0])
 
 if __name__ == "__main__":
