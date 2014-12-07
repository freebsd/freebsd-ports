--- /dev/null	2014-11-18 03:33:07.000000000 +0000
+++ build/pkgs/python/fbsd-patch-src_Doc__library__fcntl.rst	2014-11-18 03:37:12.000000000 +0000
@@ -0,0 +1,10 @@
+--- src/./Doc/library/fcntl.rst.orig	2014-07-03 21:53:41.473098625 +1000
++++ src/./Doc/library/fcntl.rst	2014-07-03 21:54:04.342833056 +1000
+@@ -50,7 +50,6 @@
+    operations are typically defined in the library module :mod:`termios` and the
+    argument handling is even more complicated.
+ 
+-   The op parameter is limited to values that can fit in 32-bits.
+    Additional constants of interest for use as the *op* argument can be
+    found in the :mod:`termios` module, under the same names as used in
+    the relevant C header files.
