--- /dev/null	2014-05-31 00:44:00.000000000 +0000
+++ build/pkgs/python/fbsd-patch-src_Lib__distutils__unixccompiler.py	2014-05-31 00:35:21.000000000 +0000
@@ -0,0 +1,15 @@
+# Description: Some python extensions can't be compiled with clang 3.4
+# Issue ID: http://bugs.python.org/issue20767
+# Submitted by: antoine
+
+--- src/./Lib/distutils/unixccompiler.py.orig      2013-11-10 07:36:40.000000000 +0000
++++ src/./Lib/distutils/unixccompiler.py   2014-02-19 15:41:48.000000000 +0000
+@@ -228,6 +228,8 @@
+         if sys.platform[:6] == "darwin":
+             # MacOSX's linker doesn't understand the -R flag at all
+             return "-L" + dir
++        elif sys.platform[:7] == "freebsd":
++            return "-Wl,-rpath=" + dir
+         elif sys.platform[:5] == "hp-ux":
+             if self._is_gcc(compiler):
+                 return ["-Wl,+s", "-L" + dir]
