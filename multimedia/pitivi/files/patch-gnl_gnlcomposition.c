--- gnl/gnlcomposition.c.orig	Mon Dec 20 13:08:16 2004
+++ gnl/gnlcomposition.c	Mon Dec 20 13:09:18 2004
@@ -860,6 +860,7 @@
 gnl_composition_nearest_cover_func (GnlComposition *comp, GstClockTime time, GnlDirection direction)
 {
   GList			*objects = comp->objects;
+  GstClockTime start;
   
   GST_INFO("Object:%s , Time[%lld], Direction:%d",
 	   gst_element_get_name(GST_ELEMENT(comp)),
@@ -903,7 +904,6 @@
     GstClockTime	last = G_MAXINT64;
     while (objects) {
       entry = (GnlCompositionEntry *) (objects->data);
-      GstClockTime start;
       
       start = entry->object->start;
       
