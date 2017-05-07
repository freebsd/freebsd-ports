--- clients/weston-info.c.orig	2016-05-19 21:36:04 UTC
+++ clients/weston-info.c
@@ -577,15 +577,24 @@ clock_name(clockid_t clk_id)
 	static const char *names[] = {
 		[CLOCK_REALTIME] =		"CLOCK_REALTIME",
 		[CLOCK_MONOTONIC] =		"CLOCK_MONOTONIC",
+#if defined(__FreeBSD__)
+		[CLOCK_REALTIME_FAST] =	"CLOCK_REALTIME_COARSE",
+		[CLOCK_MONOTONIC_FAST] =	"CLOCK_MONOTONIC_COARSE",
+#else
 		[CLOCK_MONOTONIC_RAW] =		"CLOCK_MONOTONIC_RAW",
 		[CLOCK_REALTIME_COARSE] =	"CLOCK_REALTIME_COARSE",
 		[CLOCK_MONOTONIC_COARSE] =	"CLOCK_MONOTONIC_COARSE",
+#endif
 #ifdef CLOCK_BOOTTIME
 		[CLOCK_BOOTTIME] =		"CLOCK_BOOTTIME",
 #endif
 	};
 
+#if defined(__FreeBSD__)
+	if ((unsigned)clk_id >= ARRAY_LENGTH(names))
+#else
 	if (clk_id < 0 || (unsigned)clk_id >= ARRAY_LENGTH(names))
+#endif
 		return "unknown";
 
 	return names[clk_id];
@@ -598,7 +607,11 @@ print_presentation_info(void *info)
 
 	print_global_info(info);
 
+#if defined(__FreeBSD__)
+	printf("\tpresentation clock id: %ld (%s)\n",
+#else
 	printf("\tpresentation clock id: %d (%s)\n",
+#endif
 		prinfo->clk_id, clock_name(prinfo->clk_id));
 }
 
@@ -713,7 +726,8 @@ main(int argc, char **argv)
 
 	info.display = wl_display_connect(NULL);
 	if (!info.display) {
-		fprintf(stderr, "failed to create display: %m\n");
+		fprintf(stderr, "failed to create display: %s\n",
+		    strerror(errno));
 		return -1;
 	}
 
