--- plugins/linux-v4l2/v4l2-input.c.orig	2015-03-27 21:29:37 UTC
+++ plugins/linux-v4l2/v4l2-input.c
@@ -264,7 +264,11 @@ static void v4l2_device_list(obs_propert
 	size_t cur_device_index;
 	const char *cur_device_name;
 
+#ifdef __FreeBSD__
+	dirp = opendir("/dev");
+#else
 	dirp = opendir("/sys/class/video4linux");
+#endif
 	if (!dirp)
 		return;
 
@@ -280,6 +284,11 @@ static void v4l2_device_list(obs_propert
 		uint32_t caps;
 		struct v4l2_capability video_cap;
 
+#ifdef __FreeBSD__
+		if ( strstr(dp->d_name, "video") == NULL)
+			continue;
+#endif
+
 		if (dp->d_type == DT_DIR)
 			continue;
 
@@ -596,7 +605,11 @@ static bool format_selected(obs_properti
 	uint32_t caps = 0;
 	if (v4l2_get_input_caps(dev, input, &caps) < 0)
 		return false;
+#ifdef __FreeBSD__
+	caps &= V4L2_IN_CAP_STD | V4L2_IN_CAP_CUSTOM_TIMINGS;
+#else
 	caps &= V4L2_IN_CAP_STD | V4L2_IN_CAP_DV_TIMINGS;
+#endif
 
 	obs_property_t *resolution = obs_properties_get(props, "resolution");
 	obs_property_t *framerate  = obs_properties_get(props, "framerate");
@@ -607,8 +620,13 @@ static bool format_selected(obs_properti
 	obs_property_set_visible(framerate,  (!caps) ? true : false);
 	obs_property_set_visible(standard,
 			(caps & V4L2_IN_CAP_STD) ? true : false);
+#ifdef __FreeBSD__
+	obs_property_set_visible(dv_timing,
+			(caps & V4L2_IN_CAP_CUSTOM_TIMINGS) ? true : false);
+#else
 	obs_property_set_visible(dv_timing,
 			(caps & V4L2_IN_CAP_DV_TIMINGS) ? true : false);
+#endif
 
 	if (!caps) {
 		v4l2_resolution_list(dev, obs_data_get_int(
@@ -616,8 +634,13 @@ static bool format_selected(obs_properti
 	}
 	if (caps & V4L2_IN_CAP_STD)
 		v4l2_standard_list(dev, standard);
+#ifdef __FreeBSD__
+	if (caps & V4L2_IN_CAP_CUSTOM_TIMINGS)
+		v4l2_dv_timing_list(dev, dv_timing);
+#else
 	if (caps & V4L2_IN_CAP_DV_TIMINGS)
 		v4l2_dv_timing_list(dev, dv_timing);
+#endif
 
 	v4l2_close(dev);
 
@@ -625,8 +648,13 @@ static bool format_selected(obs_properti
 		obs_property_modified(resolution, settings);
 	if (caps & V4L2_IN_CAP_STD)
 		obs_property_modified(standard, settings);
+#ifdef __FreeBSD__
+	if (caps & V4L2_IN_CAP_CUSTOM_TIMINGS)
+		obs_property_modified(dv_timing, settings);
+#else
 	if (caps & V4L2_IN_CAP_DV_TIMINGS)
 		obs_property_modified(dv_timing, settings);
+#endif
 
 	return true;
 }
@@ -828,7 +856,11 @@ static void v4l2_init(struct v4l2_data *
 		data->framerate  = -1;
 	}
 	/* set dv timing if supported */
+#ifdef __FreeBSD__
+	if (input_caps & V4L2_IN_CAP_CUSTOM_TIMINGS) {
+#else
 	if (input_caps & V4L2_IN_CAP_DV_TIMINGS) {
+#endif
 		if (v4l2_set_dv_timing(data->dev, &data->dv_timing) < 0) {
 			blog(LOG_ERROR, "Unable to set dv timing");
 			goto fail;
