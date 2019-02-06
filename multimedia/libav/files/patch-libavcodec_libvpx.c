Regressed by https://chromium.googlesource.com/webm/libvpx/+/c9a459216dc3%5E!/

libavcodec/libvpx.c:28:10: error: use of undeclared identifier 'VPX_IMG_FMT_RGB24'
    case VPX_IMG_FMT_RGB24:     return AV_PIX_FMT_RGB24;
         ^
libavcodec/libvpx.c:29:10: error: use of undeclared identifier 'VPX_IMG_FMT_RGB565'
    case VPX_IMG_FMT_RGB565:    return AV_PIX_FMT_RGB565BE;
         ^
libavcodec/libvpx.c:30:10: error: use of undeclared identifier 'VPX_IMG_FMT_RGB555'
    case VPX_IMG_FMT_RGB555:    return AV_PIX_FMT_RGB555BE;
         ^
libavcodec/libvpx.c:31:10: error: use of undeclared identifier 'VPX_IMG_FMT_UYVY'; did you mean 'VPX_IMG_FMT_YV12'?
    case VPX_IMG_FMT_UYVY:      return AV_PIX_FMT_UYVY422;
         ^~~~~~~~~~~~~~~~
libavcodec/libvpx.c:32:10: error: use of undeclared identifier 'VPX_IMG_FMT_YUY2'; did you mean 'VPX_IMG_FMT_YV12'?
    case VPX_IMG_FMT_YUY2:      return AV_PIX_FMT_YUYV422;
         ^~~~~~~~~~~~~~~~
libavcodec/libvpx.c:33:10: error: use of undeclared identifier 'VPX_IMG_FMT_YVYU'; did you mean 'VPX_IMG_FMT_YV12'?
    case VPX_IMG_FMT_YVYU:      return AV_PIX_FMT_YVYU422;
         ^~~~~~~~~~~~~~~~
libavcodec/libvpx.c:34:10: error: use of undeclared identifier 'VPX_IMG_FMT_BGR24'
    case VPX_IMG_FMT_BGR24:     return AV_PIX_FMT_BGR24;
         ^
libavcodec/libvpx.c:35:10: error: use of undeclared identifier 'VPX_IMG_FMT_ARGB'
    case VPX_IMG_FMT_ARGB:      return AV_PIX_FMT_ARGB;
         ^
libavcodec/libvpx.c:36:10: error: use of undeclared identifier 'VPX_IMG_FMT_ARGB_LE'; did you mean 'VPX_IMG_FMT_NONE'?
    case VPX_IMG_FMT_ARGB_LE:   return AV_PIX_FMT_BGRA;
         ^~~~~~~~~~~~~~~~~~~
libavcodec/libvpx.c:37:10: error: use of undeclared identifier 'VPX_IMG_FMT_RGB565_LE'; did you mean 'AV_PIX_FMT_RGB565LE'?
    case VPX_IMG_FMT_RGB565_LE: return AV_PIX_FMT_RGB565LE;
         ^~~~~~~~~~~~~~~~~~~~~
libavcodec/libvpx.c:38:10: error: use of undeclared identifier 'VPX_IMG_FMT_RGB555_LE'
    case VPX_IMG_FMT_RGB555_LE: return AV_PIX_FMT_RGB555LE;
         ^
libavcodec/libvpx.c:42:10: error: use of undeclared identifier 'VPX_IMG_FMT_444A'
    case VPX_IMG_FMT_444A:      return AV_PIX_FMT_YUVA444P;
         ^
libavcodec/libvpx.c:32:10: error: duplicate case value 'VPX_IMG_FMT_YV12'
    case VPX_IMG_FMT_YUY2:      return AV_PIX_FMT_YUYV422;
         ^
libavcodec/libvpx.c:31:10: note: previous case defined here
    case VPX_IMG_FMT_UYVY:      return AV_PIX_FMT_UYVY422;
         ^
libavcodec/libvpx.c:33:10: error: duplicate case value 'VPX_IMG_FMT_YV12'
    case VPX_IMG_FMT_YVYU:      return AV_PIX_FMT_YVYU422;
         ^
libavcodec/libvpx.c:56:42: error: use of undeclared identifier 'VPX_IMG_FMT_RGB24'
    case AV_PIX_FMT_RGB24:        return VPX_IMG_FMT_RGB24;
                                         ^
libavcodec/libvpx.c:57:42: error: use of undeclared identifier 'VPX_IMG_FMT_RGB565'
    case AV_PIX_FMT_RGB565BE:     return VPX_IMG_FMT_RGB565;
                                         ^
libavcodec/libvpx.c:58:42: error: use of undeclared identifier 'VPX_IMG_FMT_RGB555'
    case AV_PIX_FMT_RGB555BE:     return VPX_IMG_FMT_RGB555;
                                         ^
libavcodec/libvpx.c:59:42: error: use of undeclared identifier 'VPX_IMG_FMT_UYVY'; did you mean 'VPX_IMG_FMT_YV12'?
    case AV_PIX_FMT_UYVY422:      return VPX_IMG_FMT_UYVY;
                                         ^~~~~~~~~~~~~~~~
                                         VPX_IMG_FMT_YV12
libavcodec/libvpx.c:60:42: error: use of undeclared identifier 'VPX_IMG_FMT_YUY2'; did you mean 'VPX_IMG_FMT_YV12'?
    case AV_PIX_FMT_YUYV422:      return VPX_IMG_FMT_YUY2;
                                         ^~~~~~~~~~~~~~~~
                                         VPX_IMG_FMT_YV12
fatal error: too many errors emitted, stopping now [-ferror-limit=]

--- libavcodec/libvpx.c.orig	2018-02-12 21:25:59 UTC
+++ libavcodec/libvpx.c
@@ -25,6 +25,7 @@
 enum AVPixelFormat ff_vpx_imgfmt_to_pixfmt(vpx_img_fmt_t img)
 {
     switch (img) {
+#if VPX_IMAGE_ABI_VERSION < 5
     case VPX_IMG_FMT_RGB24:     return AV_PIX_FMT_RGB24;
     case VPX_IMG_FMT_RGB565:    return AV_PIX_FMT_RGB565BE;
     case VPX_IMG_FMT_RGB555:    return AV_PIX_FMT_RGB555BE;
@@ -36,10 +37,13 @@ enum AVPixelFormat ff_vpx_imgfmt_to_pixfmt(vpx_img_fmt
     case VPX_IMG_FMT_ARGB_LE:   return AV_PIX_FMT_BGRA;
     case VPX_IMG_FMT_RGB565_LE: return AV_PIX_FMT_RGB565LE;
     case VPX_IMG_FMT_RGB555_LE: return AV_PIX_FMT_RGB555LE;
+#endif
     case VPX_IMG_FMT_I420:      return AV_PIX_FMT_YUV420P;
     case VPX_IMG_FMT_I422:      return AV_PIX_FMT_YUV422P;
     case VPX_IMG_FMT_I444:      return AV_PIX_FMT_YUV444P;
+#if VPX_IMAGE_ABI_VERSION < 5
     case VPX_IMG_FMT_444A:      return AV_PIX_FMT_YUVA444P;
+#endif
 #if VPX_IMAGE_ABI_VERSION >= 3
     case VPX_IMG_FMT_I440:      return AV_PIX_FMT_YUV440P;
     case VPX_IMG_FMT_I42016:    return AV_PIX_FMT_YUV420P16BE;
@@ -53,6 +57,7 @@ enum AVPixelFormat ff_vpx_imgfmt_to_pixfmt(vpx_img_fmt
 vpx_img_fmt_t ff_vpx_pixfmt_to_imgfmt(enum AVPixelFormat pix)
 {
     switch (pix) {
+#if VPX_IMAGE_ABI_VERSION < 5
     case AV_PIX_FMT_RGB24:        return VPX_IMG_FMT_RGB24;
     case AV_PIX_FMT_RGB565BE:     return VPX_IMG_FMT_RGB565;
     case AV_PIX_FMT_RGB555BE:     return VPX_IMG_FMT_RGB555;
@@ -64,10 +69,13 @@ vpx_img_fmt_t ff_vpx_pixfmt_to_imgfmt(enum AVPixelForm
     case AV_PIX_FMT_BGRA:         return VPX_IMG_FMT_ARGB_LE;
     case AV_PIX_FMT_RGB565LE:     return VPX_IMG_FMT_RGB565_LE;
     case AV_PIX_FMT_RGB555LE:     return VPX_IMG_FMT_RGB555_LE;
+#endif
     case AV_PIX_FMT_YUV420P:      return VPX_IMG_FMT_I420;
     case AV_PIX_FMT_YUV422P:      return VPX_IMG_FMT_I422;
     case AV_PIX_FMT_YUV444P:      return VPX_IMG_FMT_I444;
+#if VPX_IMAGE_ABI_VERSION < 5
     case AV_PIX_FMT_YUVA444P:     return VPX_IMG_FMT_444A;
+#endif
 #if VPX_IMAGE_ABI_VERSION >= 3
     case AV_PIX_FMT_YUV440P:      return VPX_IMG_FMT_I440;
     case AV_PIX_FMT_YUV420P16BE:  return VPX_IMG_FMT_I42016;
