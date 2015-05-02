--- plugins/linux-v4l2/v4l2-helpers.c.orig	2015-03-27 21:29:37 UTC
+++ plugins/linux-v4l2/v4l2-helpers.c
@@ -240,6 +240,12 @@ int_fast32_t v4l2_set_standard(int_fast3
 int_fast32_t v4l2_enum_dv_timing(int_fast32_t dev, struct v4l2_dv_timings *dvt,
 		int index)
 {
+#if !defined(VIDIOC_ENUM_DV_TIMINGS) || !defined(V4L2_IN_CAP_DV_TIMINGS)
+	UNUSED_PARAMETER(dev);
+	UNUSED_PARAMETER(dvt);
+	UNUSED_PARAMETER(index);
+	return -1;
+#else
 	if (!dev || !dvt)
 		return -1;
 
@@ -253,6 +259,7 @@ int_fast32_t v4l2_enum_dv_timing(int_fas
 	memcpy(dvt, &iter.timings, sizeof(struct v4l2_dv_timings));
 
 	return 0;
+#endif
 }
 
 int_fast32_t v4l2_set_dv_timing(int_fast32_t dev, int *timing)
