--- wmmount.c.orig	Fri Jun 18 04:41:41 1999
+++ wmmount.c	Mon Jul  7 04:35:33 2003
@@ -231,7 +231,7 @@
   };
   while(true) {
     option_index=0;
-    option_c=getopt_long_only(argc, (char * const *)argv, "-h", long_options, &option_index);
+    option_c=getopt_long(argc, (char * const *)argv, "-h", long_options, &option_index);
     if(option_c==-1)
       break;
     if(option_c==1) {
