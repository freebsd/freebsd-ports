--- sys/v4l2/v4l2_calls.c.orig	2022-09-13 20:56:55 UTC
+++ sys/v4l2/v4l2_calls.c
@@ -1329,10 +1329,12 @@ gst_v4l2_query_dv_timings (GstV4l2Object * v4l2object,
 
   if (ret < 0) {
     switch (errno) {
+#ifdef ENODATA
       case ENODATA:
         GST_DEBUG_OBJECT (v4l2object->dbg_obj,
             "QUERY_DV_TIMINGS not supported for this input/output");
         break;
+#endif
       case ENOLINK:
         GST_DEBUG_OBJECT (v4l2object->dbg_obj,
             "No timings could be detected because no signal was found.");
