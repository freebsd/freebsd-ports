--- src/main.c.orig	Tue Dec  7 08:36:57 2004
+++ src/main.c	Wed Dec 29 23:06:28 2004
@@ -321,6 +321,8 @@
     Dimension    maximum_width,maximum_height;
     unsigned int gwidth=0,gheight=0;
     int          dim_forced;
+    int          opt_counter=0;
+    int          c;
 
 /*###  initializing global variables ####################################*/
 
@@ -419,8 +421,6 @@
    }
 
    /*### Manage GNU command line arguments ########################*/
-   int opt_counter = 0;
-   int c;
    while ((c = getopt_long (argc, argv, "vhu", GNU_longOptions, NULL))
 	  != -1)
      {
