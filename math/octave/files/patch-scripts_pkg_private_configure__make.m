--- scripts/pkg/private/configure_make.m.orig	2021-10-30 14:20:24 UTC
+++ scripts/pkg/private/configure_make.m
@@ -102,7 +102,7 @@ function configure_make (desc, packdir, verbose)
     endif
 
     if (exist (fullfile (src, "Makefile"), "file"))
-      [status, output] = shell (sprintf ("%s make --jobs %i --directory '%s'",
+      [status, output] = shell (sprintf ("%s gmake --jobs %i --directory '%s'",
                                          scenv, jobs, src), verbose);
       if (status != 0)
         rmdir (desc.dir, "s");
