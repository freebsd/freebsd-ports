===================================================================
RCS file: /cvs/gstreamer/gst-plugins/sys/oss/gstosselement.c,v
retrieving revision 1.35
retrieving revision 1.36
diff -u -r1.35 -r1.36
--- sys/oss/gstosselement.c	2004/04/18 20:14:36	1.35
+++ sys/oss/gstosselement.c	2004/04/29 23:45:03	1.36
@@ -1168,6 +1168,17 @@
   probe->min = gst_osselement_rate_check_rate (probe, 1000);
   n_checks++;
   probe->max = gst_osselement_rate_check_rate (probe, 100000);
+  /* a little bug workaround */
+  {
+    int max;
+
+    max = gst_osselement_rate_check_rate (probe, 48000);
+    if (max > probe->max) {
+      GST_ERROR
+          ("Driver bug recognized (driver does not round rates correctly).  Please file a bug report.");
+      probe->max = max;
+    }
+  }
   n_checks++;
   if (probe->min == -1 || probe->max == -1) {
     GST_DEBUG ("unexpected check_rate error");
