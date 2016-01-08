--- scripts/pkg/private/configure_make.m~	2016-01-08 13:18:07.395384102 +0900
+++ scripts/pkg/private/configure_make.m	2016-01-08 13:18:53.562389185 +0900
@@ -88,7 +88,7 @@
     endif
 
     if (exist (fullfile (src, "Makefile"), "file"))
-      [status, output] = shell (sprintf ("%s make --jobs %i --directory '%s'",
+      [status, output] = shell (sprintf ("%s gmake --jobs %i --directory '%s'",
                                          scenv, jobs, src), verbose);
       if (status != 0)
         rmdir (desc.dir, "s");
