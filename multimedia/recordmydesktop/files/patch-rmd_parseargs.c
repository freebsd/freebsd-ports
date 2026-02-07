--- src/rmd_parseargs.c.orig	2012-11-05 13:37:13.000000000 +0800
+++ src/rmd_parseargs.c	2012-11-05 13:40:07.000000000 +0800
@@ -106,8 +106,8 @@
     "\t--v_quality n\t\tA number from 0 to 63 for"
     " desired encoded video quality(default 63).\n"
 
-    "\t--v_bitrate n\t\tA number from 45000 to 2000000"
-    " for desired encoded video bitrate(default 45000).\n"
+    "\t--v_bitrate n\t\tA number from 0 to 2000000"
+    " for desired encoded video bitrate(default 0).\n"
 
     "\t--s_quality n\t\tDesired audio quality(-1 to 10).\n\n"
 
@@ -327,17 +327,17 @@
                  strcmp(argv[i], "-v_bitrate")  == 0) {
             if(i+1<argc){
                 int num=atoi(argv[i+1]);
-                if((num>=45000)&&(num<=2000000))
+                if((num>=0)&&(num<=2000000))
                     arg_return->v_bitrate=num;
                 else{
                     fprintf(stderr,"Argument Usage:"
-                                   " --v_bitrate n(number 45000-2000000)\n");
+                                   " --v_bitrate n(number 0-2000000)\n");
                     return FALSE;
                 }
             }
             else{
                 fprintf(stderr,"Argument Usage:"
-                               " --v_bitrate n(number 45000-2000000)\n");
+                               " --v_bitrate n(number 0-2000000)\n");
                 return FALSE;
             }
             i++;
