2004-03-20 Joe Marcus Clarke <marcus@FreeBSD.org>

* thumbnail/gst-thumbnail.c (*global*), (end_of_snap),
	(gst_thumbnail_pngenc_get):

Make sure the pipeline has completely finished before quitting the main
gst event loop.
--- thumbnail/gst-thumbnail.c.orig	Sat Mar 20 19:49:01 2004
+++ thumbnail/gst-thumbnail.c	Sat Mar 20 19:49:04 2004
@@ -23,11 +23,13 @@
 #define TIMEOUT	9999		/* how long before we give up, msec */
 
 gboolean finished = FALSE;
+gboolean can_finish = FALSE;
 
 void end_of_snap (GstElement *pipeline)
 {
 	g_print ("Snapped.\n");
-	gst_element_set_state (pipeline, GST_STATE_READY);
+	gst_element_set_state (GST_ELEMENT (pipeline), GST_STATE_NULL);
+	while (!can_finish) ;
 	gst_main_quit ();
 	finished = TRUE;
 }
@@ -97,9 +99,9 @@
 	/* commit suicide in due time if necessary */
 	g_timeout_add (TIMEOUT, (GSourceFunc) timeout, pipeline);
 	g_idle_add ((GSourceFunc) iterator, pipeline);
-	gst_main ();
 
-	gst_element_set_state (GST_ELEMENT (pipeline), GST_STATE_NULL);
+	can_finish = TRUE;
+	gst_main ();
 }
 int
 main (int argc, char *argv[])
