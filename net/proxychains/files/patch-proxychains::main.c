--- proxychains/main.c.orig	Thu Jun 24 13:13:46 2004
+++ proxychains/main.c	Thu Jun 24 13:14:05 2004
@@ -41,7 +41,7 @@
                  "More help in README file\n");
         return 0 ;
   }
-  putenv("LD_PRELOAD=/usr/lib/libproxychains.so");
+  putenv("LD_PRELOAD=" PREFIX_DIR "/lib/libproxychains.so.2");
   execvp(argv[1],&argv[1]);
   perror("proxychains can't load process....");
   return EXIT_SUCCESS;
