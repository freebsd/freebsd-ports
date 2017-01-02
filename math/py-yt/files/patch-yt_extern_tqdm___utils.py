--- yt/extern/tqdm/_utils.py.orig	2017-01-01 20:57:19 UTC
+++ yt/extern/tqdm/_utils.py
@@ -40,7 +40,7 @@ def _environ_cols_wrapper():  # pragma: 
         _environ_cols = _environ_cols_windows
         if _environ_cols is None:
             _environ_cols = _environ_cols_tput
-    if current_os in ['Linux', 'Darwin'] or current_os.startswith('CYGWIN'):
+    if current_os in ['FreeBSD', 'Linux', 'Darwin'] or current_os.startswith('CYGWIN'):
         _environ_cols = _environ_cols_linux
     return _environ_cols
 
