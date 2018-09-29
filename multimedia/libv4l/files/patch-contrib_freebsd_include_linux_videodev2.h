--- contrib/freebsd/include/linux/videodev2.h.orig	2015-05-06 19:24:59 UTC
+++ contrib/freebsd/include/linux/videodev2.h
@@ -46,7 +46,7 @@
  * All kernel-specific stuff were moved to media/v4l2-dev.h, so
  * no #if __KERNEL tests are allowed here
  *
- *	See http://linuxtv.org for more info
+ *	See https://linuxtv.org for more info
  *
  *	Author: Bill Dirks <bill@thedirks.org>
  *		Justin Schoeman
@@ -170,13 +170,12 @@ enum v4l2_buf_type {
 	V4L2_BUF_TYPE_VBI_OUTPUT           = 5,
 	V4L2_BUF_TYPE_SLICED_VBI_CAPTURE   = 6,
 	V4L2_BUF_TYPE_SLICED_VBI_OUTPUT    = 7,
-#if 1
-	/* Experimental */
 	V4L2_BUF_TYPE_VIDEO_OUTPUT_OVERLAY = 8,
-#endif
 	V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE = 9,
 	V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE  = 10,
 	V4L2_BUF_TYPE_SDR_CAPTURE          = 11,
+	V4L2_BUF_TYPE_SDR_OUTPUT           = 12,
+	V4L2_BUF_TYPE_META_CAPTURE         = 13,
 	/* Deprecated, do not use */
 	V4L2_BUF_TYPE_PRIVATE              = 0x80,
 };
@@ -191,16 +190,20 @@ enum v4l2_buf_type {
 	 || (type) == V4L2_BUF_TYPE_VIDEO_OVERLAY		\
 	 || (type) == V4L2_BUF_TYPE_VIDEO_OUTPUT_OVERLAY	\
 	 || (type) == V4L2_BUF_TYPE_VBI_OUTPUT			\
-	 || (type) == V4L2_BUF_TYPE_SLICED_VBI_OUTPUT)
+	 || (type) == V4L2_BUF_TYPE_SLICED_VBI_OUTPUT		\
+	 || (type) == V4L2_BUF_TYPE_SDR_OUTPUT)
 
 enum v4l2_tuner_type {
 	V4L2_TUNER_RADIO	     = 1,
 	V4L2_TUNER_ANALOG_TV	     = 2,
 	V4L2_TUNER_DIGITAL_TV	     = 3,
-	V4L2_TUNER_ADC               = 4,
+	V4L2_TUNER_SDR               = 4,
 	V4L2_TUNER_RF                = 5,
 };
 
+/* Deprecated, do not use */
+#define V4L2_TUNER_ADC  V4L2_TUNER_SDR
+
 enum v4l2_memory {
 	V4L2_MEMORY_MMAP             = 1,
 	V4L2_MEMORY_USERPTR          = 2,
@@ -210,32 +213,206 @@ enum v4l2_memory {
 
 /* see also http://vektor.theorem.ca/graphics/ycbcr/ */
 enum v4l2_colorspace {
-	/* ITU-R 601 -- broadcast NTSC/PAL */
+	/*
+	 * Default colorspace, i.e. let the driver figure it out.
+	 * Can only be used with video capture.
+	 */
+	V4L2_COLORSPACE_DEFAULT       = 0,
+
+	/* SMPTE 170M: used for broadcast NTSC/PAL SDTV */
 	V4L2_COLORSPACE_SMPTE170M     = 1,
 
-	/* 1125-Line (US) HDTV */
+	/* Obsolete pre-1998 SMPTE 240M HDTV standard, superseded by Rec 709 */
 	V4L2_COLORSPACE_SMPTE240M     = 2,
 
-	/* HD and modern captures. */
+	/* Rec.709: used for HDTV */
 	V4L2_COLORSPACE_REC709        = 3,
 
-	/* broken BT878 extents (601, luma range 16-253 instead of 16-235) */
+	/*
+	 * Deprecated, do not use. No driver will ever return this. This was
+	 * based on a misunderstanding of the bt878 datasheet.
+	 */
 	V4L2_COLORSPACE_BT878         = 4,
 
-	/* These should be useful.  Assume 601 extents. */
+	/*
+	 * NTSC 1953 colorspace. This only makes sense when dealing with
+	 * really, really old NTSC recordings. Superseded by SMPTE 170M.
+	 */
 	V4L2_COLORSPACE_470_SYSTEM_M  = 5,
+
+	/*
+	 * EBU Tech 3213 PAL/SECAM colorspace. This only makes sense when
+	 * dealing with really old PAL/SECAM recordings. Superseded by
+	 * SMPTE 170M.
+	 */
 	V4L2_COLORSPACE_470_SYSTEM_BG = 6,
 
-	/* I know there will be cameras that send this.  So, this is
-	 * unspecified chromaticities and full 0-255 on each of the
-	 * Y'CbCr components
+	/*
+	 * Effectively shorthand for V4L2_COLORSPACE_SRGB, V4L2_YCBCR_ENC_601
+	 * and V4L2_QUANTIZATION_FULL_RANGE. To be used for (Motion-)JPEG.
 	 */
 	V4L2_COLORSPACE_JPEG          = 7,
 
-	/* For RGB colourspaces, this is probably a good start. */
+	/* For RGB colorspaces such as produces by most webcams. */
 	V4L2_COLORSPACE_SRGB          = 8,
+
+	/* AdobeRGB colorspace */
+	V4L2_COLORSPACE_ADOBERGB      = 9,
+
+	/* BT.2020 colorspace, used for UHDTV. */
+	V4L2_COLORSPACE_BT2020        = 10,
+
+	/* Raw colorspace: for RAW unprocessed images */
+	V4L2_COLORSPACE_RAW           = 11,
+
+	/* DCI-P3 colorspace, used by cinema projectors */
+	V4L2_COLORSPACE_DCI_P3        = 12,
 };
 
+/*
+ * Determine how COLORSPACE_DEFAULT should map to a proper colorspace.
+ * This depends on whether this is a SDTV image (use SMPTE 170M), an
+ * HDTV image (use Rec. 709), or something else (use sRGB).
+ */
+#define V4L2_MAP_COLORSPACE_DEFAULT(is_sdtv, is_hdtv) \
+	((is_sdtv) ? V4L2_COLORSPACE_SMPTE170M : \
+	 ((is_hdtv) ? V4L2_COLORSPACE_REC709 : V4L2_COLORSPACE_SRGB))
+
+enum v4l2_xfer_func {
+	/*
+	 * Mapping of V4L2_XFER_FUNC_DEFAULT to actual transfer functions
+	 * for the various colorspaces:
+	 *
+	 * V4L2_COLORSPACE_SMPTE170M, V4L2_COLORSPACE_470_SYSTEM_M,
+	 * V4L2_COLORSPACE_470_SYSTEM_BG, V4L2_COLORSPACE_REC709 and
+	 * V4L2_COLORSPACE_BT2020: V4L2_XFER_FUNC_709
+	 *
+	 * V4L2_COLORSPACE_SRGB, V4L2_COLORSPACE_JPEG: V4L2_XFER_FUNC_SRGB
+	 *
+	 * V4L2_COLORSPACE_ADOBERGB: V4L2_XFER_FUNC_ADOBERGB
+	 *
+	 * V4L2_COLORSPACE_SMPTE240M: V4L2_XFER_FUNC_SMPTE240M
+	 *
+	 * V4L2_COLORSPACE_RAW: V4L2_XFER_FUNC_NONE
+	 *
+	 * V4L2_COLORSPACE_DCI_P3: V4L2_XFER_FUNC_DCI_P3
+	 */
+	V4L2_XFER_FUNC_DEFAULT     = 0,
+	V4L2_XFER_FUNC_709         = 1,
+	V4L2_XFER_FUNC_SRGB        = 2,
+	V4L2_XFER_FUNC_ADOBERGB    = 3,
+	V4L2_XFER_FUNC_SMPTE240M   = 4,
+	V4L2_XFER_FUNC_NONE        = 5,
+	V4L2_XFER_FUNC_DCI_P3      = 6,
+	V4L2_XFER_FUNC_SMPTE2084   = 7,
+};
+
+/*
+ * Determine how XFER_FUNC_DEFAULT should map to a proper transfer function.
+ * This depends on the colorspace.
+ */
+#define V4L2_MAP_XFER_FUNC_DEFAULT(colsp) \
+	((colsp) == V4L2_COLORSPACE_ADOBERGB ? V4L2_XFER_FUNC_ADOBERGB : \
+	 ((colsp) == V4L2_COLORSPACE_SMPTE240M ? V4L2_XFER_FUNC_SMPTE240M : \
+	  ((colsp) == V4L2_COLORSPACE_DCI_P3 ? V4L2_XFER_FUNC_DCI_P3 : \
+	   ((colsp) == V4L2_COLORSPACE_RAW ? V4L2_XFER_FUNC_NONE : \
+	    ((colsp) == V4L2_COLORSPACE_SRGB || (colsp) == V4L2_COLORSPACE_JPEG ? \
+	     V4L2_XFER_FUNC_SRGB : V4L2_XFER_FUNC_709)))))
+
+enum v4l2_ycbcr_encoding {
+	/*
+	 * Mapping of V4L2_YCBCR_ENC_DEFAULT to actual encodings for the
+	 * various colorspaces:
+	 *
+	 * V4L2_COLORSPACE_SMPTE170M, V4L2_COLORSPACE_470_SYSTEM_M,
+	 * V4L2_COLORSPACE_470_SYSTEM_BG, V4L2_COLORSPACE_SRGB,
+	 * V4L2_COLORSPACE_ADOBERGB and V4L2_COLORSPACE_JPEG: V4L2_YCBCR_ENC_601
+	 *
+	 * V4L2_COLORSPACE_REC709 and V4L2_COLORSPACE_DCI_P3: V4L2_YCBCR_ENC_709
+	 *
+	 * V4L2_COLORSPACE_BT2020: V4L2_YCBCR_ENC_BT2020
+	 *
+	 * V4L2_COLORSPACE_SMPTE240M: V4L2_YCBCR_ENC_SMPTE240M
+	 */
+	V4L2_YCBCR_ENC_DEFAULT        = 0,
+
+	/* ITU-R 601 -- SDTV */
+	V4L2_YCBCR_ENC_601            = 1,
+
+	/* Rec. 709 -- HDTV */
+	V4L2_YCBCR_ENC_709            = 2,
+
+	/* ITU-R 601/EN 61966-2-4 Extended Gamut -- SDTV */
+	V4L2_YCBCR_ENC_XV601          = 3,
+
+	/* Rec. 709/EN 61966-2-4 Extended Gamut -- HDTV */
+	V4L2_YCBCR_ENC_XV709          = 4,
+
+#ifndef __KERNEL__
+	/*
+	 * sYCC (Y'CbCr encoding of sRGB), identical to ENC_601. It was added
+	 * originally due to a misunderstanding of the sYCC standard. It should
+	 * not be used, instead use V4L2_YCBCR_ENC_601.
+	 */
+	V4L2_YCBCR_ENC_SYCC           = 5,
+#endif
+
+	/* BT.2020 Non-constant Luminance Y'CbCr */
+	V4L2_YCBCR_ENC_BT2020         = 6,
+
+	/* BT.2020 Constant Luminance Y'CbcCrc */
+	V4L2_YCBCR_ENC_BT2020_CONST_LUM = 7,
+
+	/* SMPTE 240M -- Obsolete HDTV */
+	V4L2_YCBCR_ENC_SMPTE240M      = 8,
+};
+
+/*
+ * enum v4l2_hsv_encoding values should not collide with the ones from
+ * enum v4l2_ycbcr_encoding.
+ */
+enum v4l2_hsv_encoding {
+
+	/* Hue mapped to 0 - 179 */
+	V4L2_HSV_ENC_180		= 128,
+
+	/* Hue mapped to 0-255 */
+	V4L2_HSV_ENC_256		= 129,
+};
+
+/*
+ * Determine how YCBCR_ENC_DEFAULT should map to a proper Y'CbCr encoding.
+ * This depends on the colorspace.
+ */
+#define V4L2_MAP_YCBCR_ENC_DEFAULT(colsp) \
+	(((colsp) == V4L2_COLORSPACE_REC709 || \
+	  (colsp) == V4L2_COLORSPACE_DCI_P3) ? V4L2_YCBCR_ENC_709 : \
+	 ((colsp) == V4L2_COLORSPACE_BT2020 ? V4L2_YCBCR_ENC_BT2020 : \
+	  ((colsp) == V4L2_COLORSPACE_SMPTE240M ? V4L2_YCBCR_ENC_SMPTE240M : \
+	   V4L2_YCBCR_ENC_601)))
+
+enum v4l2_quantization {
+	/*
+	 * The default for R'G'B' quantization is always full range, except
+	 * for the BT2020 colorspace. For Y'CbCr the quantization is always
+	 * limited range, except for COLORSPACE_JPEG: this is full range.
+	 */
+	V4L2_QUANTIZATION_DEFAULT     = 0,
+	V4L2_QUANTIZATION_FULL_RANGE  = 1,
+	V4L2_QUANTIZATION_LIM_RANGE   = 2,
+};
+
+/*
+ * Determine how QUANTIZATION_DEFAULT should map to a proper quantization.
+ * This depends on whether the image is RGB or not, the colorspace and the
+ * Y'CbCr encoding.
+ */
+#define V4L2_MAP_QUANTIZATION_DEFAULT(is_rgb_or_hsv, colsp, ycbcr_enc) \
+	(((is_rgb_or_hsv) && (colsp) == V4L2_COLORSPACE_BT2020) ? \
+	 V4L2_QUANTIZATION_LIM_RANGE : \
+	 (((is_rgb_or_hsv) || (colsp) == V4L2_COLORSPACE_JPEG) ? \
+	 V4L2_QUANTIZATION_FULL_RANGE : V4L2_QUANTIZATION_LIM_RANGE))
+
 enum v4l2_priority {
 	V4L2_PRIORITY_UNSET       = 0,  /* not initialized */
 	V4L2_PRIORITY_BACKGROUND  = 1,
@@ -306,11 +483,15 @@ struct v4l2_capability {
 
 #define V4L2_CAP_SDR_CAPTURE		0x00100000  /* Is a SDR capture device */
 #define V4L2_CAP_EXT_PIX_FORMAT		0x00200000  /* Supports the extended pixel format */
+#define V4L2_CAP_SDR_OUTPUT		0x00400000  /* Is a SDR output device */
+#define V4L2_CAP_META_CAPTURE		0x00800000  /* Is a metadata capture device */
 
 #define V4L2_CAP_READWRITE              0x01000000  /* read/write systemcalls */
 #define V4L2_CAP_ASYNCIO                0x02000000  /* async I/O */
 #define V4L2_CAP_STREAMING              0x04000000  /* streaming I/O ioctls */
 
+#define V4L2_CAP_TOUCH                  0x10000000  /* Is a touch device */
+
 #define V4L2_CAP_DEVICE_CAPS            0x80000000  /* sets device capabilities field */
 
 /*
@@ -326,6 +507,12 @@ struct v4l2_pix_format {
 	uint32_t			colorspace;	/* enum v4l2_colorspace */
 	uint32_t			priv;		/* private data, depends on pixelformat */
 	uint32_t			flags;		/* format flags (V4L2_PIX_FMT_FLAG_*) */
+	union {
+		uint32_t		ycbcr_enc;
+		uint32_t		hsv_enc;
+	};
+	uint32_t			quantization;
+	uint32_t			xfer_func;
 };
 
 /*      Pixel format         FOURCC                          depth  Description  */
@@ -360,6 +547,7 @@ struct v4l2_pix_format {
 #define V4L2_PIX_FMT_Y10     v4l2_fourcc('Y', '1', '0', ' ') /* 10  Greyscale     */
 #define V4L2_PIX_FMT_Y12     v4l2_fourcc('Y', '1', '2', ' ') /* 12  Greyscale     */
 #define V4L2_PIX_FMT_Y16     v4l2_fourcc('Y', '1', '6', ' ') /* 16  Greyscale     */
+#define V4L2_PIX_FMT_Y16_BE  v4l2_fourcc_be('Y', '1', '6', ' ') /* 16  Greyscale BE  */
 
 /* Grey bit-packed formats */
 #define V4L2_PIX_FMT_Y10BPACK    v4l2_fourcc('Y', '1', '0', 'B') /* 10  Greyscale bit-packed */
@@ -371,22 +559,16 @@ struct v4l2_pix_format {
 #define V4L2_PIX_FMT_UV8     v4l2_fourcc('U', 'V', '8', ' ') /*  8  UV 4:4 */
 
 /* Luminance+Chrominance formats */
-#define V4L2_PIX_FMT_YVU410  v4l2_fourcc('Y', 'V', 'U', '9') /*  9  YVU 4:1:0     */
-#define V4L2_PIX_FMT_YVU420  v4l2_fourcc('Y', 'V', '1', '2') /* 12  YVU 4:2:0     */
 #define V4L2_PIX_FMT_YUYV    v4l2_fourcc('Y', 'U', 'Y', 'V') /* 16  YUV 4:2:2     */
 #define V4L2_PIX_FMT_YYUV    v4l2_fourcc('Y', 'Y', 'U', 'V') /* 16  YUV 4:2:2     */
 #define V4L2_PIX_FMT_YVYU    v4l2_fourcc('Y', 'V', 'Y', 'U') /* 16 YVU 4:2:2 */
 #define V4L2_PIX_FMT_UYVY    v4l2_fourcc('U', 'Y', 'V', 'Y') /* 16  YUV 4:2:2     */
 #define V4L2_PIX_FMT_VYUY    v4l2_fourcc('V', 'Y', 'U', 'Y') /* 16  YUV 4:2:2     */
-#define V4L2_PIX_FMT_YUV422P v4l2_fourcc('4', '2', '2', 'P') /* 16  YVU422 planar */
-#define V4L2_PIX_FMT_YUV411P v4l2_fourcc('4', '1', '1', 'P') /* 16  YVU411 planar */
 #define V4L2_PIX_FMT_Y41P    v4l2_fourcc('Y', '4', '1', 'P') /* 12  YUV 4:1:1     */
 #define V4L2_PIX_FMT_YUV444  v4l2_fourcc('Y', '4', '4', '4') /* 16  xxxxyyyy uuuuvvvv */
 #define V4L2_PIX_FMT_YUV555  v4l2_fourcc('Y', 'U', 'V', 'O') /* 16  YUV-5-5-5     */
 #define V4L2_PIX_FMT_YUV565  v4l2_fourcc('Y', 'U', 'V', 'P') /* 16  YUV-5-6-5     */
 #define V4L2_PIX_FMT_YUV32   v4l2_fourcc('Y', 'U', 'V', '4') /* 32  YUV-8-8-8-8   */
-#define V4L2_PIX_FMT_YUV410  v4l2_fourcc('Y', 'U', 'V', '9') /*  9  YUV 4:1:0     */
-#define V4L2_PIX_FMT_YUV420  v4l2_fourcc('Y', 'U', '1', '2') /* 12  YUV 4:2:0     */
 #define V4L2_PIX_FMT_HI240   v4l2_fourcc('H', 'I', '2', '4') /*  8  8-bit color   */
 #define V4L2_PIX_FMT_HM12    v4l2_fourcc('H', 'M', '1', '2') /*  8  YUV 4:2:0 16x16 macroblocks */
 #define V4L2_PIX_FMT_M420    v4l2_fourcc('M', '4', '2', '0') /* 12  YUV 4:2:0 2 lines y, 1 line uv interleaved */
@@ -407,9 +589,21 @@ struct v4l2_pix_format {
 #define V4L2_PIX_FMT_NV12MT  v4l2_fourcc('T', 'M', '1', '2') /* 12  Y/CbCr 4:2:0 64x32 macroblocks */
 #define V4L2_PIX_FMT_NV12MT_16X16 v4l2_fourcc('V', 'M', '1', '2') /* 12  Y/CbCr 4:2:0 16x16 macroblocks */
 
+/* three planes - Y Cb, Cr */
+#define V4L2_PIX_FMT_YUV410  v4l2_fourcc('Y', 'U', 'V', '9') /*  9  YUV 4:1:0     */
+#define V4L2_PIX_FMT_YVU410  v4l2_fourcc('Y', 'V', 'U', '9') /*  9  YVU 4:1:0     */
+#define V4L2_PIX_FMT_YUV411P v4l2_fourcc('4', '1', '1', 'P') /* 12  YVU411 planar */
+#define V4L2_PIX_FMT_YUV420  v4l2_fourcc('Y', 'U', '1', '2') /* 12  YUV 4:2:0     */
+#define V4L2_PIX_FMT_YVU420  v4l2_fourcc('Y', 'V', '1', '2') /* 12  YVU 4:2:0     */
+#define V4L2_PIX_FMT_YUV422P v4l2_fourcc('4', '2', '2', 'P') /* 16  YVU422 planar */
+
 /* three non contiguous planes - Y, Cb, Cr */
 #define V4L2_PIX_FMT_YUV420M v4l2_fourcc('Y', 'M', '1', '2') /* 12  YUV420 planar */
 #define V4L2_PIX_FMT_YVU420M v4l2_fourcc('Y', 'M', '2', '1') /* 12  YVU420 planar */
+#define V4L2_PIX_FMT_YUV422M v4l2_fourcc('Y', 'M', '1', '6') /* 16  YUV422 planar */
+#define V4L2_PIX_FMT_YVU422M v4l2_fourcc('Y', 'M', '6', '1') /* 16  YVU422 planar */
+#define V4L2_PIX_FMT_YUV444M v4l2_fourcc('Y', 'M', '2', '4') /* 24  YUV444 planar */
+#define V4L2_PIX_FMT_YVU444M v4l2_fourcc('Y', 'M', '4', '2') /* 24  YVU444 planar */
 
 /* Bayer formats - see http://www.siliconimaging.com/RGB%20Bayer.htm */
 #define V4L2_PIX_FMT_SBGGR8  v4l2_fourcc('B', 'A', '8', '1') /*  8  BGBG.. GRGR.. */
@@ -420,10 +614,11 @@ struct v4l2_pix_format {
 #define V4L2_PIX_FMT_SGBRG10 v4l2_fourcc('G', 'B', '1', '0') /* 10  GBGB.. RGRG.. */
 #define V4L2_PIX_FMT_SGRBG10 v4l2_fourcc('B', 'A', '1', '0') /* 10  GRGR.. BGBG.. */
 #define V4L2_PIX_FMT_SRGGB10 v4l2_fourcc('R', 'G', '1', '0') /* 10  RGRG.. GBGB.. */
-#define V4L2_PIX_FMT_SBGGR12 v4l2_fourcc('B', 'G', '1', '2') /* 12  BGBG.. GRGR.. */
-#define V4L2_PIX_FMT_SGBRG12 v4l2_fourcc('G', 'B', '1', '2') /* 12  GBGB.. RGRG.. */
-#define V4L2_PIX_FMT_SGRBG12 v4l2_fourcc('B', 'A', '1', '2') /* 12  GRGR.. BGBG.. */
-#define V4L2_PIX_FMT_SRGGB12 v4l2_fourcc('R', 'G', '1', '2') /* 12  RGRG.. GBGB.. */
+	/* 10bit raw bayer packed, 5 bytes for every 4 pixels */
+#define V4L2_PIX_FMT_SBGGR10P v4l2_fourcc('p', 'B', 'A', 'A')
+#define V4L2_PIX_FMT_SGBRG10P v4l2_fourcc('p', 'G', 'A', 'A')
+#define V4L2_PIX_FMT_SGRBG10P v4l2_fourcc('p', 'g', 'A', 'A')
+#define V4L2_PIX_FMT_SRGGB10P v4l2_fourcc('p', 'R', 'A', 'A')
 	/* 10bit raw bayer a-law compressed to 8 bits */
 #define V4L2_PIX_FMT_SBGGR10ALAW8 v4l2_fourcc('a', 'B', 'A', '8')
 #define V4L2_PIX_FMT_SGBRG10ALAW8 v4l2_fourcc('a', 'G', 'A', '8')
@@ -434,11 +629,23 @@ struct v4l2_pix_format {
 #define V4L2_PIX_FMT_SGBRG10DPCM8 v4l2_fourcc('b', 'G', 'A', '8')
 #define V4L2_PIX_FMT_SGRBG10DPCM8 v4l2_fourcc('B', 'D', '1', '0')
 #define V4L2_PIX_FMT_SRGGB10DPCM8 v4l2_fourcc('b', 'R', 'A', '8')
-	/*
-	 * 10bit raw bayer, expanded to 16 bits
-	 * xxxxrrrrrrrrrrxxxxgggggggggg xxxxggggggggggxxxxbbbbbbbbbb...
-	 */
+#define V4L2_PIX_FMT_SBGGR12 v4l2_fourcc('B', 'G', '1', '2') /* 12  BGBG.. GRGR.. */
+#define V4L2_PIX_FMT_SGBRG12 v4l2_fourcc('G', 'B', '1', '2') /* 12  GBGB.. RGRG.. */
+#define V4L2_PIX_FMT_SGRBG12 v4l2_fourcc('B', 'A', '1', '2') /* 12  GRGR.. BGBG.. */
+#define V4L2_PIX_FMT_SRGGB12 v4l2_fourcc('R', 'G', '1', '2') /* 12  RGRG.. GBGB.. */
+	/* 12bit raw bayer packed, 6 bytes for every 4 pixels */
+#define V4L2_PIX_FMT_SBGGR12P v4l2_fourcc('p', 'B', 'C', 'C')
+#define V4L2_PIX_FMT_SGBRG12P v4l2_fourcc('p', 'G', 'C', 'C')
+#define V4L2_PIX_FMT_SGRBG12P v4l2_fourcc('p', 'g', 'C', 'C')
+#define V4L2_PIX_FMT_SRGGB12P v4l2_fourcc('p', 'R', 'C', 'C')
 #define V4L2_PIX_FMT_SBGGR16 v4l2_fourcc('B', 'Y', 'R', '2') /* 16  BGBG.. GRGR.. */
+#define V4L2_PIX_FMT_SGBRG16 v4l2_fourcc('G', 'B', '1', '6') /* 16  GBGB.. RGRG.. */
+#define V4L2_PIX_FMT_SGRBG16 v4l2_fourcc('G', 'R', '1', '6') /* 16  GRGR.. BGBG.. */
+#define V4L2_PIX_FMT_SRGGB16 v4l2_fourcc('R', 'G', '1', '6') /* 16  RGRG.. GBGB.. */
+
+/* HSV formats */
+#define V4L2_PIX_FMT_HSV24 v4l2_fourcc('H', 'S', 'V', '3')
+#define V4L2_PIX_FMT_HSV32 v4l2_fourcc('H', 'S', 'V', '4')
 
 /* compressed formats */
 #define V4L2_PIX_FMT_MJPEG    v4l2_fourcc('M', 'J', 'P', 'G') /* Motion-JPEG   */
@@ -456,6 +663,8 @@ struct v4l2_pix_format {
 #define V4L2_PIX_FMT_VC1_ANNEX_G v4l2_fourcc('V', 'C', '1', 'G') /* SMPTE 421M Annex G compliant stream */
 #define V4L2_PIX_FMT_VC1_ANNEX_L v4l2_fourcc('V', 'C', '1', 'L') /* SMPTE 421M Annex L compliant stream */
 #define V4L2_PIX_FMT_VP8      v4l2_fourcc('V', 'P', '8', '0') /* VP8 */
+#define V4L2_PIX_FMT_VP9      v4l2_fourcc('V', 'P', '9', '0') /* VP9 */
+#define V4L2_PIX_FMT_HEVC     v4l2_fourcc('H', 'E', 'V', 'C') /* HEVC aka H.265 */
 
 /*  Vendor-specific formats   */
 #define V4L2_PIX_FMT_CPIA1    v4l2_fourcc('C', 'P', 'I', 'A') /* cpia1 YUV */
@@ -484,6 +693,17 @@ struct v4l2_pix_format {
 #define V4L2_PIX_FMT_JPGL	v4l2_fourcc('J', 'P', 'G', 'L') /* JPEG-Lite */
 #define V4L2_PIX_FMT_SE401      v4l2_fourcc('S', '4', '0', '1') /* se401 janggu compressed rgb */
 #define V4L2_PIX_FMT_S5C_UYVY_JPG v4l2_fourcc('S', '5', 'C', 'I') /* S5C73M3 interleaved UYVY/JPEG */
+#define V4L2_PIX_FMT_Y8I      v4l2_fourcc('Y', '8', 'I', ' ') /* Greyscale 8-bit L/R interleaved */
+#define V4L2_PIX_FMT_Y12I     v4l2_fourcc('Y', '1', '2', 'I') /* Greyscale 12-bit L/R interleaved */
+#define V4L2_PIX_FMT_Z16      v4l2_fourcc('Z', '1', '6', ' ') /* Depth data 16-bit */
+#define V4L2_PIX_FMT_MT21C    v4l2_fourcc('M', 'T', '2', '1') /* Mediatek compressed block mode  */
+#define V4L2_PIX_FMT_INZI     v4l2_fourcc('I', 'N', 'Z', 'I') /* Intel Planar Greyscale 10-bit and Depth 16-bit */
+
+/* 10bit raw bayer packed, 32 bytes for every 25 pixels, last LSB 6 bits unused */
+#define V4L2_PIX_FMT_IPU3_SBGGR10	v4l2_fourcc('i', 'p', '3', 'b') /* IPU3 packed 10-bit BGGR bayer */
+#define V4L2_PIX_FMT_IPU3_SGBRG10	v4l2_fourcc('i', 'p', '3', 'g') /* IPU3 packed 10-bit GBRG bayer */
+#define V4L2_PIX_FMT_IPU3_SGRBG10	v4l2_fourcc('i', 'p', '3', 'G') /* IPU3 packed 10-bit GRBG bayer */
+#define V4L2_PIX_FMT_IPU3_SRGGB10	v4l2_fourcc('i', 'p', '3', 'r') /* IPU3 packed 10-bit RGGB bayer */
 
 /* SDR formats - used only for Software Defined Radio devices */
 #define V4L2_SDR_FMT_CU8          v4l2_fourcc('C', 'U', '0', '8') /* IQ u8 */
@@ -491,6 +711,20 @@ struct v4l2_pix_format {
 #define V4L2_SDR_FMT_CS8          v4l2_fourcc('C', 'S', '0', '8') /* complex s8 */
 #define V4L2_SDR_FMT_CS14LE       v4l2_fourcc('C', 'S', '1', '4') /* complex s14le */
 #define V4L2_SDR_FMT_RU12LE       v4l2_fourcc('R', 'U', '1', '2') /* real u12le */
+#define V4L2_SDR_FMT_PCU16BE	  v4l2_fourcc('P', 'C', '1', '6') /* planar complex u16be */
+#define V4L2_SDR_FMT_PCU18BE	  v4l2_fourcc('P', 'C', '1', '8') /* planar complex u18be */
+#define V4L2_SDR_FMT_PCU20BE	  v4l2_fourcc('P', 'C', '2', '0') /* planar complex u20be */
+
+/* Touch formats - used for Touch devices */
+#define V4L2_TCH_FMT_DELTA_TD16	v4l2_fourcc('T', 'D', '1', '6') /* 16-bit signed deltas */
+#define V4L2_TCH_FMT_DELTA_TD08	v4l2_fourcc('T', 'D', '0', '8') /* 8-bit signed deltas */
+#define V4L2_TCH_FMT_TU16	v4l2_fourcc('T', 'U', '1', '6') /* 16-bit unsigned touch data */
+#define V4L2_TCH_FMT_TU08	v4l2_fourcc('T', 'U', '0', '8') /* 8-bit unsigned touch data */
+
+/* Meta-data formats */
+#define V4L2_META_FMT_VSP1_HGO    v4l2_fourcc('V', 'S', 'P', 'H') /* R-Car VSP1 1-D Histogram */
+#define V4L2_META_FMT_VSP1_HGT    v4l2_fourcc('V', 'S', 'P', 'T') /* R-Car VSP1 2-D Histogram */
+#define V4L2_META_FMT_UVC         v4l2_fourcc('U', 'V', 'C', 'H') /* UVC Payload Header metadata */
 
 /* priv field value to indicates that subsequent fields are valid. */
 #define V4L2_PIX_FMT_PRIV_MAGIC		0xfeedcafe
@@ -513,8 +747,7 @@ struct v4l2_fmtdesc {
 #define V4L2_FMT_FLAG_COMPRESSED 0x0001
 #define V4L2_FMT_FLAG_EMULATED   0x0002
 
-#if 1
-	/* Experimental Frame Size and frame rate enumeration */
+	/* Frame Size and frame rate enumeration */
 /*
  *	F R A M E   S I Z E   E N U M E R A T I O N
  */
@@ -580,7 +813,6 @@ struct v4l2_frmivalenum {
 
 	uint32_t	reserved[2];			/* Reserved space for future use */
 };
-#endif
 
 /*
  *	T I M E C O D E
@@ -765,6 +997,8 @@ struct v4l2_buffer {
 #define V4L2_BUF_FLAG_TSTAMP_SRC_MASK		0x00070000
 #define V4L2_BUF_FLAG_TSTAMP_SRC_EOF		0x00000000
 #define V4L2_BUF_FLAG_TSTAMP_SRC_SOE		0x00010000
+/* mem2mem encoder/decoder */
+#define V4L2_BUF_FLAG_LAST			0x00100000
 
 /**
  * struct v4l2_exportbuffer - export of video buffer as DMABUF file descriptor
@@ -1073,6 +1307,9 @@ struct v4l2_standard {
  *		(aka field 2) of interlaced field formats
  * @standards:	Standards the timing belongs to
  * @flags:	Flags
+ * @picture_aspect: The picture aspect ratio (hor/vert).
+ * @cea861_vic:	VIC code as per the CEA-861 standard.
+ * @hdmi_vic:	VIC code as per the HDMI standard.
  * @reserved:	Reserved fields, must be zeroed.
  *
  * A note regarding vertical interlaced timings: height refers to the total
@@ -1102,7 +1339,10 @@ struct v4l2_bt_timings {
 	uint32_t	il_vbackporch;
 	uint32_t	standards;
 	uint32_t	flags;
-	uint32_t	reserved[14];
+	struct v4l2_fract picture_aspect;
+	uint8_t	cea861_vic;
+	uint8_t	hdmi_vic;
+	uint8_t	reserved[46];
 } __attribute__ ((packed));
 
 /* Interlaced or progressive format */
@@ -1118,6 +1358,7 @@ struct v4l2_bt_timings {
 #define V4L2_DV_BT_STD_DMT	(1 << 1)  /* VESA Discrete Monitor Timings */
 #define V4L2_DV_BT_STD_CVT	(1 << 2)  /* VESA Coordinated Video Timings */
 #define V4L2_DV_BT_STD_GTF	(1 << 3)  /* VESA Generalized Timings Formula */
+#define V4L2_DV_BT_STD_SDI	(1 << 4)  /* SDI Timings */
 
 /* Flags */
 
@@ -1143,6 +1384,36 @@ struct v4l2_bt_timings {
    exactly the same number of half-lines. Whether half-lines can be detected
    or used depends on the hardware. */
 #define V4L2_DV_FL_HALF_LINE			(1 << 3)
+/*
+ * If set, then this is a Consumer Electronics (CE) video format. Such formats
+ * differ from other formats (commonly called IT formats) in that if RGB
+ * encoding is used then by default the RGB values use limited range (i.e.
+ * use the range 16-235) as opposed to 0-255. All formats defined in CEA-861
+ * except for the 640x480 format are CE formats.
+ */
+#define V4L2_DV_FL_IS_CE_VIDEO			(1 << 4)
+/* Some formats like SMPTE-125M have an interlaced signal with a odd
+ * total height. For these formats, if this flag is set, the first
+ * field has the extra line. If not, it is the second field.
+ */
+#define V4L2_DV_FL_FIRST_FIELD_EXTRA_LINE	(1 << 5)
+/*
+ * If set, then the picture_aspect field is valid. Otherwise assume that the
+ * pixels are square, so the picture aspect ratio is the same as the width to
+ * height ratio.
+ */
+#define V4L2_DV_FL_HAS_PICTURE_ASPECT		(1 << 6)
+/*
+ * If set, then the cea861_vic field is valid and contains the Video
+ * Identification Code as per the CEA-861 standard.
+ */
+#define V4L2_DV_FL_HAS_CEA861_VIC		(1 << 7)
+/*
+ * If set, then the hdmi_vic field is valid and contains the Video
+ * Identification Code as per the HDMI standard (HDMI Vendor Specific
+ * InfoFrame).
+ */
+#define V4L2_DV_FL_HAS_HDMI_VIC			(1 << 8)
 
 /* A few useful defines to calculate the total blanking and frame sizes */
 #define V4L2_DV_BT_BLANKING_WIDTH(bt) \
@@ -1252,6 +1523,7 @@ struct v4l2_input {
 /*  Values for the 'type' field */
 #define V4L2_INPUT_TYPE_TUNER		1
 #define V4L2_INPUT_TYPE_CAMERA		2
+#define V4L2_INPUT_TYPE_TOUCH		3
 
 /* field 'status' - general */
 #define V4L2_IN_ST_NO_POWER    0x00000001  /* Attached device is off */
@@ -1266,6 +1538,8 @@ struct v4l2_input {
 /* field 'status' - analog */
 #define V4L2_IN_ST_NO_H_LOCK   0x00000100  /* No horizontal sync lock */
 #define V4L2_IN_ST_COLOR_KILL  0x00000200  /* Color killer is active */
+#define V4L2_IN_ST_NO_V_LOCK   0x00000400  /* No vertical sync lock */
+#define V4L2_IN_ST_NO_STD_LOCK 0x00000800  /* No standard format lock */
 
 /* field 'status' - digital */
 #define V4L2_IN_ST_NO_SYNC     0x00010000  /* No synchronization lock */
@@ -1281,6 +1555,7 @@ struct v4l2_input {
 #define V4L2_IN_CAP_DV_TIMINGS		0x00000002 /* Supports S_DV_TIMINGS */
 #define V4L2_IN_CAP_CUSTOM_TIMINGS	V4L2_IN_CAP_DV_TIMINGS /* For compatibility */
 #define V4L2_IN_CAP_STD			0x00000004 /* Supports S_STD */
+#define V4L2_IN_CAP_NATIVE_SIZE		0x00000008 /* Supports setting native size */
 
 /*
  *	V I D E O   O U T P U T S
@@ -1340,6 +1615,8 @@ struct v4l2_ext_controls {
 #define V4L2_CTRL_ID2CLASS(id)    ((id) & 0x0fff0000UL)
 #define V4L2_CTRL_DRIVER_PRIV(id) (((id) & 0xffff) >= 0x1000)
 #define V4L2_CTRL_MAX_DIMS	  (4)
+#define V4L2_CTRL_WHICH_CUR_VAL   0
+#define V4L2_CTRL_WHICH_DEF_VAL   0x0f000000
 
 enum v4l2_ctrl_type {
 	V4L2_CTRL_TYPE_INTEGER	     = 1,
@@ -1410,6 +1687,8 @@ struct v4l2_querymenu {
 #define V4L2_CTRL_FLAG_WRITE_ONLY 	0x0040
 #define V4L2_CTRL_FLAG_VOLATILE		0x0080
 #define V4L2_CTRL_FLAG_HAS_PAYLOAD	0x0100
+#define V4L2_CTRL_FLAG_EXECUTE_ON_WRITE	0x0200
+#define V4L2_CTRL_FLAG_MODIFY_LAYOUT	0x0400
 
 /*  Query flags, to be ORed with the control ID */
 #define V4L2_CTRL_FLAG_NEXT_CTRL	0x80000000
@@ -1562,8 +1841,6 @@ struct v4l2_audioout {
 
 /*
  *	M P E G   S E R V I C E S
- *
- *	NOTE: EXPERIMENTAL API
  */
 #if 1
 #define V4L2_ENC_IDX_FRAME_I    (0)
@@ -1809,6 +2086,9 @@ struct v4l2_plane_pix_format {
  * @plane_fmt:		per-plane information
  * @num_planes:		number of planes for this format
  * @flags:		format flags (V4L2_PIX_FMT_FLAG_*)
+ * @ycbcr_enc:		enum v4l2_ycbcr_encoding, Y'CbCr encoding
+ * @quantization:	enum v4l2_quantization, colorspace quantization
+ * @xfer_func:		enum v4l2_xfer_func, colorspace transfer function
  */
 struct v4l2_pix_format_mplane {
 	uint32_t				width;
@@ -1820,7 +2100,13 @@ struct v4l2_pix_format_mplane {
 	struct v4l2_plane_pix_format	plane_fmt[VIDEO_MAX_PLANES];
 	uint8_t				num_planes;
 	uint8_t				flags;
-	uint8_t				reserved[10];
+	union {
+		uint8_t				ycbcr_enc;
+		uint8_t				hsv_enc;
+	};
+	uint8_t				quantization;
+	uint8_t				xfer_func;
+	uint8_t				reserved[7];
 } __attribute__ ((packed));
 
 /**
@@ -2094,45 +2380,32 @@ struct v4l2_create_buffers {
 #define	VIDIOC_DBG_G_REGISTER 	_IOWR('V', 80, struct v4l2_dbg_register)
 
 #define VIDIOC_S_HW_FREQ_SEEK	 _IOW('V', 82, struct v4l2_hw_freq_seek)
-
 #define	VIDIOC_S_DV_TIMINGS	_IOWR('V', 87, struct v4l2_dv_timings)
 #define	VIDIOC_G_DV_TIMINGS	_IOWR('V', 88, struct v4l2_dv_timings)
 #define	VIDIOC_DQEVENT		 _IOR('V', 89, struct v4l2_event)
 #define	VIDIOC_SUBSCRIBE_EVENT	 _IOW('V', 90, struct v4l2_event_subscription)
 #define	VIDIOC_UNSUBSCRIBE_EVENT _IOW('V', 91, struct v4l2_event_subscription)
-
-/* Experimental, the below two ioctls may change over the next couple of kernel
-   versions */
 #define VIDIOC_CREATE_BUFS	_IOWR('V', 92, struct v4l2_create_buffers)
 #define VIDIOC_PREPARE_BUF	_IOWR('V', 93, struct v4l2_buffer)
-
-/* Experimental selection API */
 #define VIDIOC_G_SELECTION	_IOWR('V', 94, struct v4l2_selection)
 #define VIDIOC_S_SELECTION	_IOWR('V', 95, struct v4l2_selection)
-
-/* Experimental, these two ioctls may change over the next couple of kernel
-   versions. */
 #define VIDIOC_DECODER_CMD	_IOWR('V', 96, struct v4l2_decoder_cmd)
 #define VIDIOC_TRY_DECODER_CMD	_IOWR('V', 97, struct v4l2_decoder_cmd)
-
-/* Experimental, these three ioctls may change over the next couple of kernel
-   versions. */
 #define VIDIOC_ENUM_DV_TIMINGS  _IOWR('V', 98, struct v4l2_enum_dv_timings)
 #define VIDIOC_QUERY_DV_TIMINGS  _IOR('V', 99, struct v4l2_dv_timings)
 #define VIDIOC_DV_TIMINGS_CAP   _IOWR('V', 100, struct v4l2_dv_timings_cap)
-
-/* Experimental, this ioctl may change over the next couple of kernel
-   versions. */
 #define VIDIOC_ENUM_FREQ_BANDS	_IOWR('V', 101, struct v4l2_frequency_band)
 
-/* Experimental, meant for debugging, testing and internal use.
-   Never use these in applications! */
+/*
+ * Experimental, meant for debugging, testing and internal use.
+ * Never use this in applications!
+ */
 #define VIDIOC_DBG_G_CHIP_INFO  _IOWR('V', 102, struct v4l2_dbg_chip_info)
 
 #define VIDIOC_QUERY_EXT_CTRL	_IOWR('V', 103, struct v4l2_query_ext_ctrl)
 
 /* Reminder: when adding new ioctls please add support for them to
-   drivers/media/video/v4l2-compat-ioctl32.c as well! */
+   drivers/media/v4l2-core/v4l2-compat-ioctl32.c as well! */
 
 #define BASE_VIDIOC_PRIVATE	192		/* 192-255 are private */
 
