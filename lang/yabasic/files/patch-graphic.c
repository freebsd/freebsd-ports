--- graphic.c.orig	2011-09-28 10:01:08.000000000 +0800
+++ graphic.c	2011-09-28 10:01:57.000000000 +0800
@@ -748,7 +748,7 @@ grafinit (void)
 			    &visualinfo))
     {
       error (ERROR, "Could not get any TrueColor visual");
-      return;
+      return FALSE;
     }
 
   /* convert color masks in more convenient values */
@@ -790,7 +790,7 @@ grafinit (void)
       sprintf (string, "Could not find foreground color '%s'\n",
 	       background);
       error (ERROR, string);
-      return;
+      return FALSE;
     }
   forepixel =
       rgb_to_pixel (best_match.red >> 8, best_match.green >> 8,
@@ -806,7 +806,7 @@ grafinit (void)
       sprintf (string, "Could not find background color '%s'\n",
 	       background);
       error (ERROR, string);
-      return;
+      return FALSE;
     }
   backpixel =
       rgb_to_pixel (best_match.red >> 8, best_match.green >> 8,
