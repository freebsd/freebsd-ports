--- osc.c.orig	2019-10-31 18:10:02 UTC
+++ osc.c
@@ -573,7 +573,7 @@ int plugin_data_capture_of_plot(OscPlot *plot, const c
 	struct iio_device *dev, *tmp_dev = NULL;
 	struct extra_dev_info *dev_info;
 	struct marker_type *markers_copy = NULL;
-	GMutex *markers_lock;
+	GMutex *markers_lock = NULL;
 	unsigned int i, j;
 	bool new = FALSE;
 	const char *tmp = NULL;
