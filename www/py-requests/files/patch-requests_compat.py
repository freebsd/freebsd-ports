--- requests/compat.py.orig	2012-02-15 09:48:23.000000000 +0100
+++ requests/compat.py	2012-03-19 17:40:30.000000000 +0100
@@ -66,8 +66,8 @@
 # Windows-based system.
 is_windows = 'win32' in str(sys.platform).lower()
 
-# Standard Linux 2+ system.
-is_linux = ('linux' in str(sys.platform).lower())
+# Standard system.
+is_linux = ('freebsd' in str(sys.platform).lower())
 is_osx = ('darwin' in str(sys.platform).lower())
 is_hpux = ('hpux' in str(sys.platform).lower())   # Complete guess.
 is_solaris = ('solar==' in str(sys.platform).lower())   # Complete guess.
