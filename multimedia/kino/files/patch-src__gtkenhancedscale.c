--- src/gtkenhancedscale.c.orig	Mon Apr 10 03:56:16 2006
+++ src/gtkenhancedscale.c	Wed Jul 19 00:39:53 2006
@@ -33,7 +33,7 @@
 #include "gtkenhancedscale.h"
 #include <string.h>
 #include <stdio.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <math.h>
 
 #undef FANCY
@@ -159,7 +159,7 @@
 	enhanced_scale->adjustment = adjustment;
 	enhanced_scale->num_adjustments = num_adjustments;
 
-	enhanced_scale->handler_id = malloc( num_adjustments );
+	enhanced_scale->handler_id = malloc( num_adjustments * sizeof(*enhanced_scale->handler_id) );
 
 	for ( i = 0;i < num_adjustments;i++ )
 	{
@@ -254,7 +254,7 @@
 
 	enhanced_scale->trough = gdk_window_new ( widget->window, &attributes, attributes_mask );
 
-	enhanced_scale->slider = malloc( enhanced_scale->num_adjustments );
+	enhanced_scale->slider = malloc( enhanced_scale->num_adjustments * sizeof(*enhanced_scale->slider) );
 	attributes.width = ENHANCED_SCALE_CLASS ( enhanced_scale ) ->arrow_width;
 	attributes.height = ENHANCED_SCALE_CLASS ( enhanced_scale ) ->arrow_height;
 	attributes.event_mask |= ( GDK_BUTTON_MOTION_MASK |
