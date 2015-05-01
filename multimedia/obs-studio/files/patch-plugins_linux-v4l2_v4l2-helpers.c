--- plugins/linux-v4l2/v4l2-helpers.c.orig	2015-03-27 21:29:37 UTC
+++ plugins/linux-v4l2/v4l2-helpers.c
@@ -243,6 +243,9 @@ int_fast32_t v4l2_enum_dv_timing(int_fas
 	if (!dev || !dvt)
 		return -1;
 
+#ifdef __FreeBSD__
+	return 0;
+#else
 	struct v4l2_enum_dv_timings iter;
 	memset(&iter, 0, sizeof(iter));
 	iter.index   = index;
@@ -251,6 +254,8 @@ int_fast32_t v4l2_enum_dv_timing(int_fas
 		return -1;
 
 	memcpy(dvt, &iter.timings, sizeof(struct v4l2_dv_timings));
+#endif
+
 
 	return 0;
 }
