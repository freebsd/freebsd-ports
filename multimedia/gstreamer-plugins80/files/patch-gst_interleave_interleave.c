--- gst/interleave/interleave.c.orig	Thu Aug  5 14:49:14 2004
+++ gst/interleave/interleave.c	Thu Aug  5 14:50:41 2004
@@ -60,7 +60,8 @@
   GstPad *srcpad;
   GList *channels;
 
-  gint numchannels;             /* Number of pads on the element */
+  gint numpads;                 /* Number of pads on the element */
+  gint numchannels;             /* Actual number of channels */
   gint channelcount;            /* counter to get safest pad name */
   gboolean is_int;
 
@@ -96,7 +97,7 @@
         "signed = (boolean) { true, false };"
         "audio/x-raw-float, "
         "rate = (int) [ 1, MAX ], "
-        "channels = (int) 1, "
+        "channels = (int) 1,"
         "endianness = (int) BYTE_ORDER, "
         "width = (int) 32," "buffer-frames = (int) [ 0, MAX ]")
     );
@@ -203,7 +204,11 @@
   gst_pad_set_link_function (this->srcpad, interleave_link);
   gst_pad_set_getcaps_function (this->srcpad, interleave_getcaps);
 
-  this->numchannels = 0;
+  this->numchannels = 1; /* Numchannels must start with 1, even if there are
+			    no channels, as 0 channel audio is invalid
+			    and it stops people linking the interleave sink
+			    before the src */
+  this->numpads = 0;
   this->channelcount = 0;
   this->channels = NULL;
 }
@@ -232,7 +237,9 @@
   gst_pad_set_getcaps_function (channel->sinkpad, interleave_getcaps);
 
   this->channels = g_list_append (this->channels, channel);
-  this->numchannels++;
+  if (this->numpads > 0)
+    this->numchannels++;
+  this->numpads++;
   this->channelcount++;
 
   GST_DEBUG ("interleave added pad %s\n", name);
@@ -261,7 +268,9 @@
 
       p = p->next;
       this->channels = g_list_remove_link (this->channels, p_copy);
-      this->numchannels--;
+      this->numpads--;
+      if (this->numpads > 0)
+	this->numchannels--;
 
       g_list_free (p_copy);
 
@@ -476,7 +485,7 @@
 
   /* if in the future int gets a buffer-frames property, we should switch here
    * on the type */
-  do_float_interleave ((gfloat **) data_in, this->numchannels,
+  do_float_interleave ((gfloat **) data_in, this->numpads,
       (gfloat *) data_out, to_process_bytes / sizeof (gfloat));
 
   /* clean up and push */
