--- gst/schedulers/gstoptimalscheduler.c.orig	Fri Jul  2 23:38:37 2004
+++ gst/schedulers/gstoptimalscheduler.c	Fri Jul  2 23:38:42 2004
@@ -2276,7 +2277,7 @@
 
       GST_LOG ("elements still have links with other elements in the group");
 
-      while (group->elements)
+      while (group && group->elements)
         for (l = group->elements; l && l->data; l = l->next) {
           GstElement *element = (GstElement *) l->data;
 
@@ -2309,7 +2310,7 @@
           }
 
           if (linkcount < 2) {
-            remove_from_group (group, element);
+            group = remove_from_group (group, element);
           }
           /* if linkcount == 2, it will be unlinked later on */
           else if (linkcount > 2) {
