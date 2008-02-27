--- scripts/pkg/pkg.m~	2007-12-20 16:55:26.000000000 +0000
+++ scripts/pkg/pkg.m	2008-02-25 16:32:59.000000000 +0000
@@ -1052,7 +1052,7 @@
     ## make
     if (exist (fullfile (src, "Makefile"), "file"))
       [status, output] = shell (strcat ("export INSTALLDIR=\"", desc.dir,
-					 "\"; make -C ", src));
+					 "\"; gmake -C ", src));
       if (status != 0)
 	rm_rf (desc.dir);
 	error ("'make' returned the following error: %s", output);
