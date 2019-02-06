Regressed by https://chromium.googlesource.com/webm/libvpx/+/c9a459216dc3%5E!/

codec/vpx.c:119:23: error: use of undeclared identifier 'VPX_IMG_FMT_444A'
    { VLC_CODEC_YUVA, VPX_IMG_FMT_444A, 8, 0 },
                      ^
codec/vpx.c:120:23: error: use of undeclared identifier 'VPX_IMG_FMT_YUY2'; did you mean 'VPX_IMG_FMT_YV12'?
    { VLC_CODEC_YUYV, VPX_IMG_FMT_YUY2, 8, 0 },
                      ^~~~~~~~~~~~~~~~
codec/vpx.c:121:23: error: use of undeclared identifier 'VPX_IMG_FMT_UYVY'; did you mean 'VPX_IMG_FMT_YV12'?
    { VLC_CODEC_UYVY, VPX_IMG_FMT_UYVY, 8, 0 },
                      ^~~~~~~~~~~~~~~~
codec/vpx.c:122:23: error: use of undeclared identifier 'VPX_IMG_FMT_YVYU'; did you mean 'VPX_IMG_FMT_YV12'?
    { VLC_CODEC_YVYU, VPX_IMG_FMT_YVYU, 8, 0 },
                      ^~~~~~~~~~~~~~~~
codec/vpx.c:124:24: error: use of undeclared identifier 'VPX_IMG_FMT_RGB555'
    { VLC_CODEC_RGB15, VPX_IMG_FMT_RGB555, 8, 0 },
                       ^
codec/vpx.c:125:24: error: use of undeclared identifier 'VPX_IMG_FMT_RGB565'
    { VLC_CODEC_RGB16, VPX_IMG_FMT_RGB565, 8, 0 },
                       ^
codec/vpx.c:126:24: error: use of undeclared identifier 'VPX_IMG_FMT_RGB24'
    { VLC_CODEC_RGB24, VPX_IMG_FMT_RGB24, 8, 0 },
                       ^
codec/vpx.c:127:24: error: use of undeclared identifier 'VPX_IMG_FMT_RGB32'
    { VLC_CODEC_RGB32, VPX_IMG_FMT_RGB32, 8, 0 },
                       ^
codec/vpx.c:129:23: error: use of undeclared identifier 'VPX_IMG_FMT_ARGB'
    { VLC_CODEC_ARGB, VPX_IMG_FMT_ARGB, 8, 0 },
                      ^
codec/vpx.c:130:23: error: use of undeclared identifier 'VPX_IMG_FMT_ARGB_LE'; did you mean 'VPX_IMG_FMT_NONE'?
    { VLC_CODEC_BGRA, VPX_IMG_FMT_ARGB_LE, 8, 0 },
                      ^~~~~~~~~~~~~~~~~~~
codec/vpx.c:150:34: error: invalid application of 'sizeof' to an incomplete type 'const struct (anonymous struct at codec/vpx.c:104:14) []'
    for( unsigned int i = 0; i < ARRAY_SIZE(chroma_table); i++ )
                                 ^~~~~~~~~~~~~~~~~~~~~~~~

--- modules/codec/vpx.c.orig	2018-03-29 12:04:52 UTC
+++ modules/codec/vpx.c
@@ -116,18 +116,6 @@ static const struct
     { VLC_CODEC_I440, VPX_IMG_FMT_I440, 8, 0 },
 
     { VLC_CODEC_YV12, VPX_IMG_FMT_YV12, 8, 0 },
-    { VLC_CODEC_YUVA, VPX_IMG_FMT_444A, 8, 0 },
-    { VLC_CODEC_YUYV, VPX_IMG_FMT_YUY2, 8, 0 },
-    { VLC_CODEC_UYVY, VPX_IMG_FMT_UYVY, 8, 0 },
-    { VLC_CODEC_YVYU, VPX_IMG_FMT_YVYU, 8, 0 },
-
-    { VLC_CODEC_RGB15, VPX_IMG_FMT_RGB555, 8, 0 },
-    { VLC_CODEC_RGB16, VPX_IMG_FMT_RGB565, 8, 0 },
-    { VLC_CODEC_RGB24, VPX_IMG_FMT_RGB24, 8, 0 },
-    { VLC_CODEC_RGB32, VPX_IMG_FMT_RGB32, 8, 0 },
-
-    { VLC_CODEC_ARGB, VPX_IMG_FMT_ARGB, 8, 0 },
-    { VLC_CODEC_BGRA, VPX_IMG_FMT_ARGB_LE, 8, 0 },
 
     { VLC_CODEC_GBR_PLANAR, VPX_IMG_FMT_I444, 8, 1 },
     { VLC_CODEC_GBR_PLANAR_10L, VPX_IMG_FMT_I44416, 10, 1 },
