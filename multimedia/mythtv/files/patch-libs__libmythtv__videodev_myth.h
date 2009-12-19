--- libs/libmythtv/videodev_myth.h.orig	2009-07-06 22:42:28.000000000 +0200
+++ libs/libmythtv/videodev_myth.h	2009-11-15 13:08:20.000000000 +0100
@@ -11,6 +11,36 @@
 typedef uint8_t  __u8; 
 typedef uint32_t __u64; 
 typedef int32_t  __s64;  // HACK. Non 64bit FreeBSD kernels require this for ioctls
+
+typedef struct fb_var_screeninfo
+{
+	int xres;
+	int yres;
+	int bits_per_pixel;
+	int xres_virtual;
+	int yres_virtual;
+	int xoffset;
+	int yoffset;
+	int nonstd;
+	int activate;
+};
+
+typedef struct fb_fix_screeninfo
+{
+	int smem_start;
+};
+
+#define FB_ACTIVATE_NOW 0
+
+#define FBIOBLANK 0
+#define FBIOGET_FSCREENINFO 0
+#define FBIOGET_VSCREENINFO 0
+#define FBIOPAN_DISPLAY 0
+#define FBIOPUT_VSCREENINFO 0
+
+#define VESA_NO_BLANKING 0
+#define VESA_VSYNC_SUSPEND 0
+
 #else
 #include <linux/types.h>
 #include <linux/version.h>
