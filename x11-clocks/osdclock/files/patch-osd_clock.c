--- osd_clock.c.orig	Thu Mar 29 19:10:24 2001
+++ osd_clock.c	Fri Aug  6 08:05:45 2004
@@ -109,7 +109,15 @@
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
+  xosd_set_shadow_offset(osd, shadow);
+  
   if (!osd)
   {
     fprintf (stderr, "Error initializing osd\n");
@@ -127,11 +135,12 @@
     output = malloc(255 * sizeof(char));
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
