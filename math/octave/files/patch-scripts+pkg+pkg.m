--- scripts/pkg/pkg.m~	2009-07-27 18:31:53.000000000 +0900
+++ scripts/pkg/pkg.m	2009-07-27 18:32:52.000000000 +0900
@@ -1247,7 +1247,7 @@
     ## Make.
     if (exist (fullfile (src, "Makefile"), "file"))
       [status, output] = shell (cstrcat ("export INSTALLDIR=\"", desc.dir,
-					 "\"; make -C '", src, "'"));
+					 "\"; gmake -C '", src, "'"));
       if (status != 0)
 	rm_rf (desc.dir);
 	error ("'make' returned the following error: %s", output);
