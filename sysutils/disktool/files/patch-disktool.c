--- disktool.c.orig	1998-04-17 15:32:43.000000000 -0700
+++ disktool.c	2013-09-17 09:15:50.943959620 -0700
@@ -168,9 +168,9 @@
 }
 
 /* ==========================================================================*/
-long kbytes(blocks, blocksize)
-     long blocks;
-     long blocksize;
+int64_t kbytes(blocks, blocksize)
+     int64_t blocks;
+     uint64_t blocksize;
 {
   /* Return number of kilobytes given the number of blocks and the block size.
      This isn't quite trivial because a 32 bit signed long integer could easily
@@ -361,7 +361,7 @@
 Panel_item item;
 Event  *event;
 {
-   return;
+   return 0;
 }
 
 /* ========================================================================*/
@@ -376,7 +376,7 @@
    timer.it_interval.tv_sec = xv_get(inc_item, PANEL_VALUE);
    notify_set_itimer_func(frame, get_values,
 			  ITIMER_REAL, &timer, NULL);
-   return;
+   return 0;
 }
 /* ========================================================================*/
 int
@@ -397,7 +397,7 @@
 	     xv_get(thresh_item, PANEL_VALUE)/1000, NULL);
       xv_set(thresh_item, PANEL_MAX_VALUE, 3000, NULL);
    }
-   return;
+   return 0;
 }
 
 /* ========================================================================*/
@@ -488,7 +488,7 @@
    thresh[curr_item] = xv_get(thresh_item, PANEL_VALUE);
    get_values();
    reposition_widgets();
-   return;
+   return 0;
 }
 
 /* ========================================================================*/
@@ -507,7 +507,7 @@
    }
    get_values();
    reposition_widgets();
-   return;
+   return 0;
 }
 
 /* ========================================================================*/
@@ -517,7 +517,7 @@
 int    value;
 Event  *event;
 {
-   return;
+   return 0;
 }
 
 /* ========================================================================*/
