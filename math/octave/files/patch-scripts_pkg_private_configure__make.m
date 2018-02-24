--- scripts/pkg/private/configure_make.m.orig	2017-02-22 18:01:55 UTC
+++ scripts/pkg/private/configure_make.m
@@ -87,7 +87,7 @@ function configure_make (desc, packdir, 
     endif
 
     if (exist (fullfile (src, "Makefile"), "file"))
-      [status, output] = shell (sprintf ("%s make --jobs %i --directory '%s'",
+      [status, output] = shell (sprintf ("%s gmake --jobs %i --directory '%s'",
                                          scenv, jobs, src), verbose);
       if (status != 0)
         rmdir (desc.dir, "s");
