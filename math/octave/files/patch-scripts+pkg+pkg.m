--- scripts/pkg/pkg.m.orig	2011-02-08 19:00:51.000000000 +0900
+++ scripts/pkg/pkg.m	2011-05-09 12:18:05.000000000 +0900
@@ -1326,7 +1326,7 @@
 
     ## Make.
     if (exist (fullfile (src, "Makefile"), "file"))
-      [status, output] = shell (cstrcat (scenv, "make -C '", src, "'"));
+      [status, output] = shell (cstrcat (scenv, "gmake -C '", src, "'"));
       if (status != 0)
         rm_rf (desc.dir);
         error ("'make' returned the following error: %s", output);
