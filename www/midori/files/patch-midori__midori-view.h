--- ./midori/midori-view.h.orig	2012-09-19 21:17:43.000000000 +0000
+++ ./midori/midori-view.h	2012-09-21 14:17:03.000000000 +0000
@@ -35,6 +35,13 @@
     MIDORI_NEW_VIEW_WINDOW
 } MidoriNewView;
 
+typedef enum
+{
+    MIDORI_DELAY_UNDELAYED = -1, /* The view is in a regular undelayed state */
+    MIDORI_DELAY_DELAYED = 1, /* The view is delayed but has not displayed any indication of such */
+    MIDORI_DELAY_PENDING_UNDELAY = -2 /* The view is delayed and showing a message asking to be undelayed */
+} MidoriDelay;
+
 GType
 midori_new_view_get_type (void) G_GNUC_CONST;
 
