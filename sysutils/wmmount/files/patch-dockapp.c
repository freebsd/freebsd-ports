--- dockapp.c.orig	Fri Jun 18 04:41:41 1999
+++ dockapp.c	Mon Jul  7 04:34:44 2003
@@ -89,7 +89,7 @@
   dockapp_argv=argv;
   while(true) {
     option_index=0;
-    option_c=getopt_long_only(argc, argv, "-hwsaf:b:", long_options, &option_index);
+    option_c=getopt_long(argc, argv, "-hwsaf:b:", long_options, &option_index);
     if(option_c==-1)
       break;
     if(option_c==0) {
