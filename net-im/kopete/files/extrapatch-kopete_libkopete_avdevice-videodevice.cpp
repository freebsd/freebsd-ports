--- kopete/libkopete/avdevice/videodevice.cpp	2009-01-06 19:45:41.000000000 +0100
+++ kopete/libkopete/avdevice/videodevice.cpp	2009-01-06 19:47:03.000000000 +0100
@@ -181,7 +181,7 @@
 		m_videostream=false;
 
 		m_driver=VIDEODEV_DRIVER_NONE;
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 
 //if(!getWorkaroundBrokenDriver())
@@ -512,7 +512,7 @@
 	m_io_method = IO_METHOD_NONE;
 	switch(m_driver)
 	{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 		case VIDEODEV_DRIVER_V4L2:
 			if(V4L2_capabilities.capabilities & V4L2_CAP_READWRITE)
@@ -558,7 +558,7 @@
 	}
 
 // Select video input, video standard and tune here.
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 	cropcap.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
 	if (-1 == xioctl (VIDIOC_CROPCAP, &cropcap))
@@ -676,7 +676,7 @@
 // Change resolution for the video device
 		switch(m_driver)
 		{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 			case VIDEODEV_DRIVER_V4L2:
 //				CLEAR (fmt);
@@ -778,7 +778,7 @@
 // Change the pixel format for the video device
 	switch(m_driver)
 	{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 		case VIDEODEV_DRIVER_V4L2:
 //			CLEAR (fmt);
@@ -867,7 +867,7 @@
 	{
 		switch (m_driver)
 		{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 			case VIDEODEV_DRIVER_V4L2:
 				if (-1 == ioctl (descriptor, VIDIOC_S_INPUT, &newinput))
@@ -935,7 +935,7 @@
 			case IO_METHOD_READ: // Nothing to do
 				break;
 			case IO_METHOD_MMAP:
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 				{
 					unsigned int loop;
@@ -957,7 +957,7 @@
 #endif
 				break;
 			case IO_METHOD_USERPTR:
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 				{
 					unsigned int loop;
@@ -995,7 +995,7 @@
     /// @todo implement me
 	ssize_t bytesread;
 
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 	struct v4l2_buffer v4l2buffer;
 #endif
@@ -1029,7 +1029,7 @@
 				}
 				break;
 			case IO_METHOD_MMAP:
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 				CLEAR (v4l2buffer);
 				v4l2buffer.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
@@ -1089,7 +1089,7 @@
 #endif
 				break;
 			case IO_METHOD_USERPTR:
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 				{
 					unsigned int i;
@@ -1475,7 +1475,7 @@
 
 	switch(m_driver)
 	{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 		case VIDEODEV_DRIVER_V4L2:
 			{
@@ -1545,7 +1545,7 @@
 
 	switch(m_driver)
 	{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 		case VIDEODEV_DRIVER_V4L2:
 			{
@@ -1615,7 +1615,7 @@
 
 	switch(m_driver)
 	{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 		case VIDEODEV_DRIVER_V4L2:
 			{
@@ -1685,7 +1685,7 @@
 
 	switch(m_driver)
 	{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 		case VIDEODEV_DRIVER_V4L2:
 			{
@@ -1755,7 +1755,7 @@
 
 	switch(m_driver)
 	{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 		case VIDEODEV_DRIVER_V4L2:
 			{
@@ -1876,7 +1876,7 @@
 {
 	switch(m_driver)
 	{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 		case VIDEODEV_DRIVER_V4L2:
 			switch(palette)
@@ -1939,7 +1939,6 @@
 				case VIDEO_PALETTE_RGB32	: return PIXELFORMAT_RGB32;	break;
 				case VIDEO_PALETTE_YUYV		: return PIXELFORMAT_YUYV;	break;
 				case VIDEO_PALETTE_UYVY		: return PIXELFORMAT_UYVY;	break;
-				case VIDEO_PALETTE_YUV420	:
 				case VIDEO_PALETTE_YUV420P	: return PIXELFORMAT_YUV420P;	break;
 				case VIDEO_PALETTE_YUV422P	: return PIXELFORMAT_YUV422P;	break;
 			}
@@ -1956,7 +1955,7 @@
 {
 	switch(m_driver)
 	{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 		case VIDEODEV_DRIVER_V4L2:
 			switch(pixelformat)
@@ -2031,7 +2030,7 @@
 				case PIXELFORMAT_GREY	: return VIDEO_PALETTE_GREY;	break;
 				case PIXELFORMAT_YUYV	: return VIDEO_PALETTE_YUYV;	break;
 				case PIXELFORMAT_UYVY	: return VIDEO_PALETTE_UYVY;	break;
-				case PIXELFORMAT_YUV420P: return VIDEO_PALETTE_YUV420;	break;
+				case PIXELFORMAT_YUV420P: return VIDEO_PALETTE_YUV420P;	break;
 				case PIXELFORMAT_YUV422P: return VIDEO_PALETTE_YUV422P;	break;
 
 // Compressed formats
@@ -2084,7 +2083,11 @@
 		case PIXELFORMAT_GREY	: return 8;	break;
 		case PIXELFORMAT_YUYV	: return 16;	break;
 		case PIXELFORMAT_UYVY	: return 16;	break;
+#if defined(__FreeBSD__)
+		case PIXELFORMAT_YUV420P: return 24;	break;
+#else
 		case PIXELFORMAT_YUV420P: return 16;	break;
+#endif
 		case PIXELFORMAT_YUV422P: return 16;	break;
 
 // Compressed formats
@@ -2162,7 +2165,7 @@
 	returnvalue = "None";
 	switch(m_driver)
 	{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 		case VIDEODEV_DRIVER_V4L2:
 			switch(pixelformat)
@@ -2224,7 +2227,6 @@
 				case VIDEO_PALETTE_RGB32	: returnvalue = pixelFormatName(PIXELFORMAT_RGB32);	break;
 				case VIDEO_PALETTE_YUYV		: returnvalue = pixelFormatName(PIXELFORMAT_YUYV);	break;
 				case VIDEO_PALETTE_UYVY		: returnvalue = pixelFormatName(PIXELFORMAT_UYVY);	break;
-				case VIDEO_PALETTE_YUV420	:
 				case VIDEO_PALETTE_YUV420P	: returnvalue = pixelFormatName(PIXELFORMAT_YUV420P);	break;
 				case VIDEO_PALETTE_YUV422P	: returnvalue = pixelFormatName(PIXELFORMAT_YUV422P);	break;
 			}
@@ -2242,7 +2244,7 @@
 			int err = 0;
 	switch(m_driver)
 	{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 		case VIDEODEV_DRIVER_V4L2:
 			fmtdesc.index = 0;
@@ -2319,7 +2321,7 @@
 {
 	switch(m_driver)
 	{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 		case VIDEODEV_DRIVER_V4L2:
 			switch(standard)
@@ -2461,7 +2463,7 @@
 	returnvalue = "None";
 	switch(m_driver)
 	{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 		case VIDEODEV_DRIVER_V4L2:
 			switch(standard)
@@ -2531,7 +2533,7 @@
 {
 	switch(m_driver)
 	{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 		case VIDEODEV_DRIVER_V4L2:
 			break;
