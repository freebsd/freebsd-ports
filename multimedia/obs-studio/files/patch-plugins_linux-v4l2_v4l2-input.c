--- plugins/linux-v4l2/v4l2-input.c.orig	2015-03-27 21:29:37 UTC
+++ plugins/linux-v4l2/v4l2-input.c
@@ -41,6 +41,12 @@ along with this program.  If not, see <h
 #include "v4l2-udev.h"
 #endif
 
+/* The new dv timing api was introduced in Linux 3.4
+ * Currently we simply disable dv timings when this is not defined */
+#if !defined(VIDIOC_ENUM_DV_TIMINGS) || !defined(V4L2_IN_CAP_DV_TIMINGS)
+#define V4L2_IN_CAP_DV_TIMINGS 0
+#endif
+
 #define V4L2_DATA(voidptr) struct v4l2_data *data = voidptr;
 
 #define timeval2ns(tv) \
@@ -74,7 +80,6 @@ struct v4l2_data {
 	obs_source_t *source;
 	pthread_t thread;
 	os_event_t *event;
-	void *udev;
 
 	int_fast32_t dev;
 	int width;
@@ -298,9 +303,14 @@ static void v4l2_device_list(obs_propert
 			continue;
 		}
 
+#ifndef V4L2_CAP_DEVICE_CAPS
+		caps = video_cap.capabilities;
+#else
+		/* ... since Linux 3.3 */
 		caps = (video_cap.capabilities & V4L2_CAP_DEVICE_CAPS)
 			? video_cap.device_caps
 			: video_cap.capabilities;
+#endif
 
 		if (!(caps & V4L2_CAP_VIDEO_CAPTURE)) {
 			blog(LOG_INFO, "%s seems to not support video capture",
@@ -663,12 +673,15 @@ static bool resolution_selected(obs_prop
  * If everything went fine we can start capturing again when the device is
  * reconnected
  */
-static void device_added(const char *dev, void *vptr)
+static void device_added(void *vptr, calldata_t *calldata)
 {
 	V4L2_DATA(vptr);
 
 	obs_source_update_properties(data->source);
 
+	const char *dev;
+	calldata_get_string(calldata, "device", &dev);
+
 	if (strcmp(data->device_id, dev))
 		return;
 
@@ -681,12 +694,15 @@ static void device_added(const char *dev
  *
  * We stop recording here so we don't block the device node
  */
-static void device_removed(const char *dev, void *vptr)
+static void device_removed(void *vptr, calldata_t *calldata)
 {
 	V4L2_DATA(vptr);
 
 	obs_source_update_properties(data->source);
 
+	const char *dev;
+	calldata_get_string(calldata, "device", &dev);
+
 	if (strcmp(data->device_id, dev))
 		return;
 
@@ -779,7 +795,12 @@ static void v4l2_destroy(void *vptr)
 		bfree(data->device_id);
 
 #if HAVE_UDEV
-	v4l2_unref_udev(data->udev);
+	signal_handler_t *sh = v4l2_get_udev_signalhandler();
+
+	signal_handler_disconnect(sh, "device_added", device_added, data);
+	signal_handler_disconnect(sh, "device_removed", device_removed, data);
+
+	v4l2_unref_udev();
 #endif
 
 	bfree(data);
@@ -924,12 +945,22 @@ static void *v4l2_create(obs_data_t *set
 	data->dev = -1;
 	data->source = source;
 
+	/* Bitch about build problems ... */
+#ifndef V4L2_CAP_DEVICE_CAPS
+	blog(LOG_WARNING, "Plugin built without device caps support!");
+#endif
+#if !defined(VIDIOC_ENUM_DV_TIMINGS) || !defined(V4L2_IN_CAP_DV_TIMINGS)
+	blog(LOG_WARNING, "Plugin built without dv-timing support!");
+#endif
+
 	v4l2_update(data, settings);
 
 #if HAVE_UDEV
-	data->udev = v4l2_init_udev();
-	v4l2_set_device_added_callback(data->udev, &device_added, data);
-	v4l2_set_device_removed_callback(data->udev, &device_removed, data);
+	v4l2_init_udev();
+	signal_handler_t *sh = v4l2_get_udev_signalhandler();
+
+	signal_handler_connect(sh, "device_added", &device_added, data);
+	signal_handler_connect(sh, "device_removed", &device_removed, data);
 #endif
 
 	return data;
