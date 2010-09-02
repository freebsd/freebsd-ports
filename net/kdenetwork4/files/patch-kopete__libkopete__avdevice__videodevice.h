--- ./kopete/libkopete/avdevice/videodevice.h.orig	2009-03-18 13:00:00.000000000 +0300
+++ ./kopete/libkopete/avdevice/videodevice.h	2010-03-28 14:25:38.820037067 +0400
@@ -63,6 +63,13 @@
 
 #endif // __linux__
 
+#if defined(__FreeBSD__) && defined(ENABLE_AV)
+#include <linux/videodev.h>
+#ifdef HAVE_LIBV4L2
+#include <libv4l2.h>
+#endif // HAVE_LIBV4L2
+#endif
+
 #include <qstring.h>
 #include <qfile.h>
 #include <qimage.h>
@@ -80,7 +87,7 @@
 typedef enum
 {
 	VIDEODEV_DRIVER_NONE
-#if defined( __linux__) && defined(ENABLE_AV)
+#if (defined( __linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
         ,
 	VIDEODEV_DRIVER_V4L
 #ifdef V4L2_CAP_VIDEO_CAPTURE
@@ -327,7 +334,7 @@
 	QVector<Kopete::AV::VideoInput> m_input;
 
 protected:
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined( __linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 	/*!
 	    \enum VideoDevice::imgctrl_id Control-IDs used for V4L1- and software-controls
 	 */
@@ -356,7 +363,7 @@
 	int descriptor;
 	videodev_driver m_driver;
 	QString m_model;
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined( __linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 	struct v4l2_capability V4L2_capabilities;
 	struct v4l2_format fmt;
@@ -388,7 +395,7 @@
 	virtual int initDevice();
 
 	void setupControls();
-#if defined(__linux__) && defined(ENABLE_AV) && defined(V4L2_CAP_VIDEO_CAPTURE)
+#if (defined( __linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV) && defined(V4L2_CAP_VIDEO_CAPTURE)
 	bool getMenuCtrlOptions(quint32 id, quint32 maxindex, QStringList * options);
 	void saveV4L2ControlData(struct v4l2_queryctrl qctrl);
 	const char *getUnifiedV4L2StdCtrlName(quint32 std_ctrl_id);
