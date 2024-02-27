--- _cabal_deps/rawfilepath-1.1.0/cbits/runProcess.c.orig	2023-08-24 02:59:07 UTC
+++ _cabal_deps/rawfilepath-1.1.0/cbits/runProcess.c
@@ -249,7 +249,7 @@ runInteractiveProcess (char *const args[],
         /* the child */
         if (environment) {
             // XXX Check result
-            execvpe(args[0], args, environment);
+            __hsunix_execvpe(args[0], args, environment);
         } else {
             // XXX Check result
             execvp(args[0], args);
