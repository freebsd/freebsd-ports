--- scripts/pkg/pkg.m~	2008-07-22 00:59:05.000000000 +0900
+++ scripts/pkg/pkg.m	2008-08-23 05:47:31.000000000 +0900
@@ -1242,7 +1242,7 @@
     ## make
     if (exist (fullfile (src, "Makefile"), "file"))
       [status, output] = shell (cstrcat ("export INSTALLDIR=\"", desc.dir,
-					 "\"; make -C ", src));
+					 "\"; gmake -C ", src));
       if (status != 0)
 	rm_rf (desc.dir);
 	error ("'make' returned the following error: %s", output);
