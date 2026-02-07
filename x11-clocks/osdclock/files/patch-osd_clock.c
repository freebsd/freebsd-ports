--- osd_clock.c.orig	Sun Apr  8 02:50:01 2001
+++ osd_clock.c	Tue Jan  4 16:27:20 2005
@@ -57,8 +57,9 @@
   int offset = 0;
   int shadow = 2;
   int interval = 1;
-
-  while ((c = getopt_long(argc ,argv,"f:c:d:F:i:s:o:tbh",
+  int horizontal_offset = 0;
+  
+  while ((c = getopt_long(argc ,argv,"f:c:d:F:i:s:o:tbH:h",
 			  long_options, NULL)) != -1)
   {
     switch(c)
@@ -90,6 +91,9 @@
       case 'b':
 	pos = XOSD_bottom;
 	break;
+      case 'H':
+	horizontal_offset = atoi(optarg);
+	break;
       case 'h':
 	printf("USAGE: %s [-flag args]\n"
 		"\t-f\tfully qualified font.  default: fixed\n"
@@ -102,6 +106,7 @@
 		"\t-d\tDelay (time the clock stays on screen when it's updated)\n"
 	        "\t\tin seconds\n"
 		"\t-i\tInterval (time between updates) in seconds\n"
+		"\t-H\thorizontal offset. default: 0\n"
 		"\t-h\tthis help message\n",
 		argv[0]);
 	return EXIT_SUCCESS;
@@ -109,7 +114,16 @@
     }
   }
   
-  osd = xosd_init (font, color, delay, pos, offset, shadow);
+  osd = xosd_create(1);
+
+  xosd_set_font(osd, font);
+  xosd_set_colour(osd, color);
+  xosd_set_timeout(osd, delay);
+  xosd_set_pos(osd, pos);
+  xosd_set_vertical_offset(osd, offset);
+  xosd_set_horizontal_offset(osd, horizontal_offset);
+  xosd_set_shadow_offset(osd, shadow);
+  
   if (!osd)
   {
     fprintf (stderr, "Error initializing osd\n");
@@ -126,11 +140,12 @@
    
     strftime(output, 255, format, localtime(&curr_time));
 
-    xosd_display (osd, 1, XOSD_string, output);
+    if ((xosd_display (osd, 0, XOSD_string, output)) == -1) 
+	    (void)fprintf(stderr, "xosd_display() failed\n");
     sleep(interval);
   }
 
-  xosd_uninit (osd);
+  xosd_destroy (osd);
   
   return EXIT_SUCCESS;
 }
