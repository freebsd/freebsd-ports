--- scripts/pkg/private/configure_make.m.orig	2022-11-02 18:19:56 UTC
+++ scripts/pkg/private/configure_make.m
@@ -110,7 +110,7 @@ function configure_make (desc, packdir, verbose)
     endif
 
     if (exist (fullfile (src, "Makefile"), "file"))
-      [status, output] = shell (sprintf ("%s make --jobs %i --directory '%s'",
+      [status, output] = shell (sprintf ("%s gmake --jobs %i --directory '%s'",
                                          scenv, jobs, src), verbose);
       if (status != 0)
         disp (output);
