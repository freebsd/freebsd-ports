--- freebsd/drivers/dahdi/dahdi-base.c.orig	2015-03-22 00:41:01.893409000 +0600
+++ freebsd/drivers/dahdi/dahdi-base.c	2015-03-22 00:47:34.870157000 +0600
@@ -4344,8 +4344,7 @@
 		if (spans[i]->manufacturer)
 			dahdi_copy_string(stack.spaninfo.manufacturer, spans[i]->manufacturer,
 				sizeof(stack.spaninfo.manufacturer));
-		if (spans[i]->devicetype)
-			dahdi_copy_string(stack.spaninfo.devicetype, spans[i]->devicetype, sizeof(stack.spaninfo.devicetype));
+		dahdi_copy_string(stack.spaninfo.devicetype, spans[i]->devicetype, sizeof(stack.spaninfo.devicetype));
 		dahdi_copy_string(stack.spaninfo.location, spans[i]->location, sizeof(stack.spaninfo.location));
 		if (spans[i]->spantype)
 			dahdi_copy_string(stack.spaninfo.spantype, spans[i]->spantype, sizeof(stack.spaninfo.spantype));
@@ -4406,10 +4405,9 @@
 			dahdi_copy_string(stack.spaninfo_v1.manufacturer,
 				spans[i]->manufacturer,
 				sizeof(stack.spaninfo_v1.manufacturer));
-		if (spans[i]->devicetype)
-			dahdi_copy_string(stack.spaninfo_v1.devicetype,
-					  spans[i]->devicetype,
-					  sizeof(stack.spaninfo_v1.devicetype));
+		dahdi_copy_string(stack.spaninfo_v1.devicetype,
+				  spans[i]->devicetype,
+				  sizeof(stack.spaninfo_v1.devicetype));
 		dahdi_copy_string(stack.spaninfo_v1.location,
 				  spans[i]->location,
 				  sizeof(stack.spaninfo_v1.location));
@@ -9263,7 +9261,9 @@
 	.d_poll		= dahdi_device_poll,
 	.d_mmap		= dahdi_device_mmap,
 	.d_name		= "dahdi",
-#if __FreeBSD_version >= 800039
+#if __FreeBSD_version >= 1000000
+	.d_flags	= D_TRACKCLOSE | D_NEEDMINOR,
+#elif __FreeBSD_version >= 800039
 	.d_flags	= D_PSEUDO | D_TRACKCLOSE | D_NEEDMINOR
 #else
 	.d_flags	= D_PSEUDO | D_TRACKCLOSE
