--- ./discover_main.c.orig	2013-10-10 13:25:59.000000000 -0400
+++ ./discover_main.c	2013-10-10 13:26:13.000000000 -0400
@@ -33,7 +33,7 @@
   grok_init(&grok);
 
   int pattern_count = 0;
-  while ((opt = getopt_long_only(argc, argv, "hp:v", options, &optind)) != -1) {
+  while ((opt = getopt_long_only(argc, argv, "hp:v", options, NULL)) != -1) {
     switch (opt) {
       case 'h':
         usage();
