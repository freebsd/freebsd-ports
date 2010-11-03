--- ./kopete/libkopete/avdevice/videodevice.h.orig	2010-03-30 12:28:37.000000000 +0400
+++ ./kopete/libkopete/avdevice/videodevice.h	2010-10-31 23:13:07.574296355 +0300
@@ -32,9 +32,11 @@
 #include <unistd.h>
 #include <signal.h>
 
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 
+#if defined(__linux__)
 #include <asm/types.h>
+#endif
 #undef __STRICT_ANSI__
 #ifndef __u64 //required by videodev.h
 #define __u64 unsigned long long
@@ -48,8 +50,10 @@
 #define pgoff_t unsigned long
 #endif
 
+#if defined(__linux__)
 #include <linux/fs.h>
 #include <linux/kernel.h>
+#endif
 #include <linux/videodev.h>
 #define VIDEO_MODE_PAL_Nc  3
 #define VIDEO_MODE_PAL_M   4
@@ -61,7 +65,7 @@
 #include <libv4l2.h>
 #endif // HAVE_V4L2
 
-#endif // __linux__
+#endif // __linux__ __FreeBSD__ ENABLE_AV
 
 #include <qstring.h>
 #include <qfile.h>
@@ -80,7 +84,7 @@
 typedef enum
 {
 	VIDEODEV_DRIVER_NONE
-#if defined( __linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
         ,
 	VIDEODEV_DRIVER_V4L
 #ifdef V4L2_CAP_VIDEO_CAPTURE
@@ -327,7 +331,7 @@
 	QVector<Kopete::AV::VideoInput> m_input;
 
 protected:
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 	/*!
 	    \enum VideoDevice::imgctrl_id Control-IDs used for V4L1- and software-controls
 	 */
@@ -356,7 +360,7 @@
 	int descriptor;
 	videodev_driver m_driver;
 	QString m_model;
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 #ifdef V4L2_CAP_VIDEO_CAPTURE
 	struct v4l2_capability V4L2_capabilities;
 	struct v4l2_format fmt;
@@ -388,7 +392,7 @@
 	virtual int initDevice();
 
 	void setupControls();
-#if defined(__linux__) && defined(ENABLE_AV) && defined(V4L2_CAP_VIDEO_CAPTURE)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV) && defined(V4L2_CAP_VIDEO_CAPTURE)
 	bool getMenuCtrlOptions(quint32 id, quint32 maxindex, QStringList * options);
 	void saveV4L2ControlData(struct v4l2_queryctrl qctrl);
 	const char *getUnifiedV4L2StdCtrlName(quint32 std_ctrl_id);
