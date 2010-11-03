--- ./kopete/libkopete/avdevice/videodevice.cpp.orig	2010-10-01 01:22:38.000000000 +0400
+++ ./kopete/libkopete/avdevice/videodevice.cpp	2010-10-31 23:13:07.584295519 +0300
@@ -57,7 +57,7 @@
  */
 void VideoDevice::setupControls()
 {
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 	bool driver_vflip = false;
 	bool driver_hflip = false;
 #endif
@@ -68,7 +68,7 @@
 
 	switch(m_driver)
 	{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 		case VIDEODEV_DRIVER_V4L2:
 			struct v4l2_queryctrl qctrl;
@@ -146,7 +146,7 @@
 			break;
 	}
 	
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 	// Software controls:
 	BooleanVideoControl boolCtrl;
 	boolCtrl.value_default = 0;
@@ -171,7 +171,7 @@
 #endif
 }
 
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 /*!
     \fn bool VideoDevice::getMenuCtrlOptions(quint32 id, quint32 maxindex, QStringList * options)
@@ -379,7 +379,7 @@
 		m_videostream=false;
 
 		m_driver=VIDEODEV_DRIVER_NONE;
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 
 		CLEAR(V4L2_capabilities);
@@ -649,7 +649,7 @@
 	m_io_method = IO_METHOD_NONE;
 	switch(m_driver)
 	{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 		case VIDEODEV_DRIVER_V4L2:
 			if(V4L2_capabilities.capabilities & V4L2_CAP_READWRITE)
@@ -695,7 +695,7 @@
 	}
 
 // Select video input, video standard and tune here.
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 	struct v4l2_cropcap cropcap;
 	struct v4l2_crop crop;
@@ -826,7 +826,7 @@
 // Change resolution for the video device
 		switch(m_driver)
 		{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 			case VIDEODEV_DRIVER_V4L2:
 //				CLEAR (fmt);
@@ -932,7 +932,7 @@
 // Change the pixel format for the video device
 	switch(m_driver)
 	{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 		case VIDEODEV_DRIVER_V4L2:
 //			CLEAR (fmt);
@@ -1025,7 +1025,7 @@
 	{
 		switch (m_driver)
 		{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 			case VIDEODEV_DRIVER_V4L2:
 				if (-1 == ioctl (descriptor, VIDIOC_S_INPUT, &newinput))
@@ -1076,7 +1076,7 @@
 			case IO_METHOD_READ: // Nothing to do
 				break;
 			case IO_METHOD_MMAP:
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 				{
 					unsigned int loop;
@@ -1098,7 +1098,7 @@
 #endif
 				break;
 			case IO_METHOD_USERPTR:
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 				{
 					unsigned int loop;
@@ -1136,7 +1136,7 @@
     /// @todo implement me
 	ssize_t bytesread;
 
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 	struct v4l2_buffer v4l2buffer;
 #endif
@@ -1175,7 +1175,7 @@
 				}
 				break;
 			case IO_METHOD_MMAP:
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 				CLEAR (v4l2buffer);
 				v4l2buffer.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
@@ -1211,7 +1211,7 @@
 #endif
 				break;
 			case IO_METHOD_USERPTR:
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 				{
 					unsigned int i;
@@ -1724,7 +1724,7 @@
 	if (!isOpen())
 		return EXIT_FAILURE;
 
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 	if (ctrl_id == IMGCTRL_ID_SOFT_AUTOBRIGHTNESSCONTRASTCORR)
 	{
 		if (m_current_input < m_input.size() )
@@ -1773,7 +1773,7 @@
 
 	switch(m_driver)
 	{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 		case VIDEODEV_DRIVER_V4L2:
 			{
@@ -1864,7 +1864,7 @@
 	if (!isOpen())
 		return EXIT_FAILURE;
 
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 	if (ctrl_id == IMGCTRL_ID_SOFT_AUTOBRIGHTNESSCONTRASTCORR)
 	{
 		if (m_current_input < m_input.size() )
@@ -1909,7 +1909,7 @@
 
 	switch(m_driver)
 	{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 		case VIDEODEV_DRIVER_V4L2:
 			{
@@ -2012,7 +2012,7 @@
 {
 	switch(m_driver)
 	{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 		case VIDEODEV_DRIVER_V4L2:
 			switch(palette)
@@ -2092,7 +2092,7 @@
 {
 	switch(m_driver)
 	{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 		case VIDEODEV_DRIVER_V4L2:
 			switch(pixelformat)
@@ -2298,7 +2298,7 @@
 	returnvalue = "None";
 	switch(m_driver)
 	{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 		case VIDEODEV_DRIVER_V4L2:
 			switch(pixelformat)
@@ -2378,7 +2378,7 @@
 			int err = 0;
 	switch(m_driver)
 	{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 		case VIDEODEV_DRIVER_V4L2:
 			struct v4l2_fmtdesc fmtdesc;
@@ -2456,7 +2456,7 @@
 {
 	switch(m_driver)
 	{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 		case VIDEODEV_DRIVER_V4L2:
 			switch(standard)
@@ -2640,7 +2640,7 @@
 	returnvalue = "None";
 	switch(m_driver)
 	{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 		case VIDEODEV_DRIVER_V4L2:
 			switch(standard)
@@ -2726,7 +2726,7 @@
 	{
 	switch(m_driver)
 		{
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 			case VIDEODEV_DRIVER_V4L2:
 
@@ -2998,7 +2998,7 @@
 }
 
 
-#if defined(__linux__) && defined(ENABLE_AV)  && defined(V4L2_CAP_VIDEO_CAPTURE)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)  && defined(V4L2_CAP_VIDEO_CAPTURE)
 /*!
     \fn const char * VideoDevice::getUnifiedV4L2StdCtrlName(quint32 std_ctrl_id)
     \param std_ctrl_id ID of the V4L2 standard video control
