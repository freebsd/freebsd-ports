--- scripts/pkg/private/configure_make.m.orig	2014-01-20 06:14:25.000000000 -0700
+++ scripts/pkg/private/configure_make.m	2014-01-20 06:16:15.000000000 -0700
@@ -75,7 +75,7 @@
 
     ## Make.
     if (exist (fullfile (src, "Makefile"), "file"))
-      [status, output] = shell ([scenv "make -C '" src "'"], verbose);
+      [status, output] = shell ([scenv "gmake -C '" src "'"], verbose);
       if (status != 0)
         rmdir (desc.dir, "s");
         disp (output);
