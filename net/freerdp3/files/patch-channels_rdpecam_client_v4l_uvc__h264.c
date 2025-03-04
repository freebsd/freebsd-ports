--- channels/rdpecam/client/v4l/uvc_h264.c.orig	2025-02-14 08:49:47 UTC
+++ channels/rdpecam/client/v4l/uvc_h264.c
@@ -25,9 +25,111 @@
 
 #include <sys/ioctl.h>
 
+#ifndef __FreeBSD__
+
 #include <linux/uvcvideo.h>
 #include <linux/videodev2.h>
 #include <libusb-1.0/libusb.h>
+
+#else // __FreeBSD__
+
+#include <sys/ioctl.h>
+#include <sys/types.h>
+#include <libusb.h>
+#include <libv4l1-videodev.h>
+
+/*
+ * Dynamic controls
+ */
+
+/* Data types for UVC control data */
+#define UVC_CTRL_DATA_TYPE_RAW		0
+#define UVC_CTRL_DATA_TYPE_SIGNED	1
+#define UVC_CTRL_DATA_TYPE_UNSIGNED	2
+#define UVC_CTRL_DATA_TYPE_BOOLEAN	3
+#define UVC_CTRL_DATA_TYPE_ENUM		4
+#define UVC_CTRL_DATA_TYPE_BITMASK	5
+
+/* Control flags */
+#define UVC_CTRL_FLAG_SET_CUR		(1 << 0)
+#define UVC_CTRL_FLAG_GET_CUR		(1 << 1)
+#define UVC_CTRL_FLAG_GET_MIN		(1 << 2)
+#define UVC_CTRL_FLAG_GET_MAX		(1 << 3)
+#define UVC_CTRL_FLAG_GET_RES		(1 << 4)
+#define UVC_CTRL_FLAG_GET_DEF		(1 << 5)
+/* Control should be saved at suspend and restored at resume. */
+#define UVC_CTRL_FLAG_RESTORE		(1 << 6)
+/* Control can be updated by the camera. */
+#define UVC_CTRL_FLAG_AUTO_UPDATE	(1 << 7)
+/* Control supports asynchronous reporting */
+#define UVC_CTRL_FLAG_ASYNCHRONOUS	(1 << 8)
+
+#define UVC_CTRL_FLAG_GET_RANGE \
+	(UVC_CTRL_FLAG_GET_CUR | UVC_CTRL_FLAG_GET_MIN | \
+	 UVC_CTRL_FLAG_GET_MAX | UVC_CTRL_FLAG_GET_RES | \
+	 UVC_CTRL_FLAG_GET_DEF)
+
+struct uvc_menu_info {
+	uint32_t value;
+	uint8_t name[32];
+};
+
+struct uvc_xu_control_mapping {
+	uint32_t id;
+	uint8_t name[32];
+	uint8_t entity[16];
+	uint8_t selector;
+
+	uint8_t size;
+	uint8_t offset;
+	uint32_t v4l2_type;
+	uint32_t data_type;
+
+	struct uvc_menu_info  *menu_info;
+	uint32_t menu_count;
+
+	uint32_t reserved[4];
+};
+
+struct uvc_xu_control_query {
+	uint8_t unit;
+	uint8_t selector;
+	uint8_t query;		/* Video Class-Specific Request Code, */
+				/* defined in linux/usb/video.h A.8.  */
+	uint16_t size;
+	uint8_t  *data;
+};
+
+#define UVCIOC_CTRL_MAP		_IOWR('u', 0x20, struct uvc_xu_control_mapping)
+#define UVCIOC_CTRL_QUERY	_IOWR('u', 0x21, struct uvc_xu_control_query)
+
+/*
+ * Metadata node
+ */
+
+/**
+ * struct uvc_meta_buf - metadata buffer building block
+ * @ns: system timestamp of the payload in nanoseconds
+ * @sof: USB Frame Number
+ * @length: length of the payload header
+ * @flags: payload header flags
+ * @buf: optional device-specific header data
+ *
+ * UVC metadata nodes fill buffers with possibly multiple instances of this
+ * struct. The first two fields are added by the driver, they can be used for
+ * clock synchronisation. The rest is an exact copy of a UVC payload header.
+ * Only complete objects with complete buffers are included. Therefore it's
+ * always sizeof(meta->ts) + sizeof(meta->sof) + meta->length bytes large.
+ */
+struct uvc_meta_buf {
+	uint64_t ns;
+	uint16_t sof;
+	uint8_t length;
+	uint8_t flags;
+	uint8_t buf[];
+} __packed;
+
+#endif // __FreeBSD__
 
 #include "uvc_h264.h"
 
