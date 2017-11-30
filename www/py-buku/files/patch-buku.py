--- buku.py.orig	2017-11-10 05:21:06 UTC
+++ buku.py
@@ -2050,7 +2050,7 @@ class BukuDb:
 
         FF_BM_DB_PATH = None
 
-        if sys.platform.startswith('linux'):
+        if sys.platform.startswith('linux') or sys.platform.startswith('freebsd'):
             GC_BM_DB_PATH = '~/.config/google-chrome/Default/Bookmarks'
             CB_BM_DB_PATH = '~/.config/chromium/Default/Bookmarks'
 
