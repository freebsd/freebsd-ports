--- pixmap/pixmap_theme_draw.c.orig	Mon Feb  7 03:33:43 2000
+++ pixmap/pixmap_theme_draw.c	Fri Apr 12 15:24:40 2002
@@ -403,8 +403,9 @@
 		      gdk_gc_set_clip_origin(gc, 0, 0);
 		    }
 		}
-	      gdk_imlib_free_pixmap(p);
 	    }
+	  if (p)
+	    gdk_imlib_free_pixmap(p);
 	  gdk_imlib_destroy_image(im);
 	}
     }
@@ -467,8 +468,9 @@
 	  gdk_gc_set_clip_mask(gc, NULL);
 	  gdk_gc_set_clip_origin(gc, 0, 0);
 	}
-      gdk_imlib_free_pixmap(p);
     }
+  if (p)
+    gdk_imlib_free_pixmap(p);
   gdk_imlib_destroy_image(im);
 }
 
@@ -591,8 +593,9 @@
 		  gdk_gc_set_clip_mask(gc, NULL);
 		  gdk_gc_set_clip_origin(gc, 0, 0);
 		}
-	      gdk_imlib_free_pixmap(p);
 	    }
+	  if (p)
+	    gdk_imlib_free_pixmap(p);
 	  gdk_imlib_destroy_image(im);
 	}
     }
@@ -956,11 +959,13 @@
 		  gdk_gc_set_clip_mask(gc, NULL);
 		  gdk_gc_set_clip_origin(gc, 0, 0);
 		}
-
-	      gdk_imlib_free_pixmap(p);
-	      gdk_imlib_free_pixmap(p1);
-	      gdk_imlib_free_pixmap(p2);
 	    }
+	  if (p)
+	    gdk_imlib_free_pixmap(p);
+	  if (p1)
+	    gdk_imlib_free_pixmap(p1);
+	  if (p2)
+	    gdk_imlib_free_pixmap(p2);
 	  gdk_imlib_destroy_image(im);
 	  gdk_imlib_destroy_image(im1);
 	  gdk_imlib_destroy_image(im2);
@@ -1202,11 +1207,15 @@
 		  gdk_gc_set_clip_mask(gc, NULL);
 		  gdk_gc_set_clip_origin(gc, 0, 0);
 		}
-	      gdk_imlib_free_pixmap(p);
-	      gdk_imlib_free_pixmap(p1);
-	      gdk_imlib_free_pixmap(p2);
-	      gdk_imlib_free_pixmap(p3);
 	    }
+	  if (p)
+	    gdk_imlib_free_pixmap(p);
+	  if (p1)
+	    gdk_imlib_free_pixmap(p1);
+	  if (p2)
+	    gdk_imlib_free_pixmap(p2);
+	  if (p3)
+	    gdk_imlib_free_pixmap(p3);
 	  gdk_imlib_destroy_image(im);
 	  gdk_imlib_destroy_image(im1);
 	  gdk_imlib_destroy_image(im2);

