--- libs/libmythtv/videodev2.h.orig	2019-01-14 11:53:51 UTC
+++ libs/libmythtv/videodev2.h
@@ -53,25 +53,14 @@
  *              Hans Verkuil <hverkuil@xs4all.nl>
  *		et al.
  */
-#ifndef __LINUX_VIDEODEV2_H
+
+#ifdef __FreeBSD__
+#include <linux/videodev2.h>
+#elif !defined(__LINUX_VIDEODEV2_H)
 #define __LINUX_VIDEODEV2_H
 
 #include <sys/time.h>
 
-#ifdef __FreeBSD__
-#include <linux/input.h>	// For __[us][0-9]+ types
-#define __le64 __u64
-#define __le32 __u32
-#define __le16 __u16
-#define __le8  __u8
-#define __be64 __u64
-#define __be32 __u32
-#define __be16 __u16
-#define __be8  __u8
-#else
-#include <linux/ioctl.h>
-#include <linux/types.h>
-#endif
 #include <linux/v4l2-common.h>
 #include <linux/v4l2-controls.h>
 
