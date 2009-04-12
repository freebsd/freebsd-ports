--- scripts/pkg/pkg.m~	2009-04-09 17:26:54.000000000 +0900
+++ scripts/pkg/pkg.m	2009-04-09 17:27:14.000000000 +0900
@@ -1242,7 +1242,7 @@
     ## make
     if (exist (fullfile (src, "Makefile"), "file"))
       [status, output] = shell (strcat ("export INSTALLDIR=\"", desc.dir,
- 					 "\"; make -C '", src, "'"));
+ 					 "\"; gmake -C '", src, "'"));
       if (status != 0)
 	rm_rf (desc.dir);
 	error ("'make' returned the following error: %s", output);
