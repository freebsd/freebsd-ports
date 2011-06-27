--- libavutil/avutil.h.orig	2011-06-28 00:24:47.927592990 +0200
+++ libavutil/avutil.h	2011-06-28 00:26:11.892760214 +0200
@@ -112,7 +112,8 @@
 #define FF_API_OLD_IMAGE_NAMES (LIBAVUTIL_VERSION_MAJOR < 51)
 #endif
 enum AVPictureType {
-    AV_PICTURE_TYPE_I = 1, ///< Intra
+    AV_PICTURE_TYPE_NONE = 0, ///< Undefined
+    AV_PICTURE_TYPE_I,     ///< Intra
     AV_PICTURE_TYPE_P,     ///< Predicted
     AV_PICTURE_TYPE_B,     ///< Bi-dir predicted
     AV_PICTURE_TYPE_S,     ///< S(GMC)-VOP MPEG4
