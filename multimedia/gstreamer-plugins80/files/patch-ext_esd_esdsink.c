--- ext/esd/esdsink.c	3 Aug 2003 20:48:40 -0000	1.10.4.1
+++ ext/esd/esdsink.c	25 Sep 2003 00:25:05 -0000
@@ -281,7 +281,8 @@
  
     switch(GST_EVENT_TYPE(event)){
       case GST_EVENT_EOS:
-	break;
+	gst_pad_event_default(pad, event);
+	return;
       case GST_EVENT_DISCONTINUOUS:
       {
 	gint64 value;
@@ -293,11 +294,12 @@
 	  //esdsink->handled = 0;
 	}
  	//esdsink->resync = TRUE;
-	break;
+	gst_pad_event_default(pad, event);
+	return;
       }
       default:
 	gst_pad_event_default(pad, event);
-	break;
+	return;
     }
     gst_event_unref(event);
     return;
