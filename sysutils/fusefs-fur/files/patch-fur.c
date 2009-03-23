--- fur.c.orig	2009-03-21 02:19:24.000000000 +0900
+++ fur.c	2009-03-21 08:02:46.000000000 +0900
@@ -88,7 +88,6 @@
 
 
 #define SIMIL_PROC
-#define FUSE_USE_VERSION 22
 #include <time.h>
 #include <fuse.h>
 #include <stdlib.h>
@@ -385,7 +384,7 @@
   init();
   fuse_opt_parse(&args, NULL, NULL, NULL);
   fuse_opt_add_arg(&args, "-s");
-  retval=fuse_main(args.argc, args.argv, &hello_oper);
+  retval=fuse_main(args.argc, args.argv, &hello_oper, NULL);
 
   fuse_opt_free_args(&args);
   // Finalize RAPI
