--- Makefile.PL.orig	2009-06-03 14:24:20.000000000 +0000
+++ Makefile.PL	2009-06-03 14:24:42.000000000 +0000
@@ -35,11 +35,11 @@
 
 EOF
 
-checklibs 
-    lib => 'ssh2',
-    header => 'libssh2.h',
-    libpath => [@search_libs, $lib],
-    incpath => [@search_incs, $inc];
+#checklibs 
+#    lib => 'ssh2',
+#    header => 'libssh2.h',
+#    libpath => [@search_libs, $lib],
+#    incpath => [@search_incs, $inc];
 
 if (!$lib && !$inc) {
     $lib = (join ' ', map "-L$_", @search_libs) . " -lssh2 $extra_libs";
