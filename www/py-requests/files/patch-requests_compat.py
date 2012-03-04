--- requests/compat.py.orig	2012-01-23 06:35:35.000000000 +0000
+++ requests/compat.py	2012-02-07 15:46:29.000000000 +0000
@@ -4,7 +4,6 @@
 pythoncompat
 """
 
-
 import sys
 
 # -------
@@ -66,8 +65,8 @@
 # Windows-based system.
 is_windows = 'win32' in str(sys.platform).lower()
 
-# Standard Linux 2+ system.
-is_linux = ('linux' in str(sys.platform).lower())
+# Standard system.
+is_linux = ('freebsd' in str(sys.platform).lower())
 is_osx = ('darwin' in str(sys.platform).lower())
 is_hpux = ('hpux' in str(sys.platform).lower())   # Complete guess.
 is_solaris = ('solar==' in str(sys.platform).lower())   # Complete guess.
