--- scripts/pkg/pkg.m~	2009-03-09 11:04:57.000000000 +0900
+++ scripts/pkg/pkg.m	2009-03-09 11:05:12.000000000 +0900
@@ -1239,7 +1239,7 @@
     ## Make.
     if (exist (fullfile (src, "Makefile"), "file"))
       [status, output] = shell (cstrcat ("export INSTALLDIR=\"", desc.dir,
-					 "\"; make -C '", src, "'"));
+					 "\"; gmake -C '", src, "'"));
       if (status != 0)
 	rm_rf (desc.dir);
 	error ("'make' returned the following error: %s", output);
