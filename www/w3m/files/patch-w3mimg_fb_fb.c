--- w3mimg/fb/fb.c.orig	2003-07-14 01:19:10.000000000 +0900
+++ w3mimg/fb/fb.c	2007-11-23 08:59:36.000000000 +0900
@@ -12,12 +12,24 @@
 #include <errno.h>
 #include <sys/ioctl.h>
 #include <sys/mman.h>
+#if defined(__linux__)
 #include <linux/fb.h>
+#elif defined(__FreeBSD__)
+#include <sys/fbio.h> 
+#endif
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <machine/param.h>
+#endif
 
 #include "fb.h"
 
 #define FB_ENV		"FRAMEBUFFER"
+#if defined(__linux__)
 #define	FB_DEFDEV	"/dev/fb0"
+#elif defined(__FreeBSD__)
+#define	FB_DEFDEV	"/dev/ttyv0"
+#endif
 
 #define MONO_OFFSET_8BIT  0x40
 #define COLORS_MONO_8BIT  0x40
@@ -38,22 +50,65 @@
 
 #define IMAGE_SIZE_MAX 10000
 
+#if defined(__linux__)
 static struct fb_cmap *fb_cmap_create(struct fb_fix_screeninfo *,
 				      struct fb_var_screeninfo *);
+#elif defined(__FreeBSD__)
+static video_color_palette_t *fb_cmap_create(video_info_t *video_info,
+				video_adapter_info_t *video_adapter_info);
+#endif
+#if defined(__linux__)
 static void fb_cmap_destroy(struct fb_cmap *cmap);
+#elif defined(__FreeBSD__)
+static void fb_cmap_destroy(video_color_palette_t *cmap);
+#endif
+#if defined(__linux__)
 static int fb_fscrn_get(int fbfp, struct fb_fix_screeninfo *scinfo);
+#endif
+#if defined(__linux__)
 static void *fb_mmap(int fbfp, struct fb_fix_screeninfo *scinfo);
+#elif defined(__FreeBSD__)
+static void *fb_mmap(int fbfp, video_adapter_info_t *video_adapter_info);
+#endif
+#if defined(__linux__)
 static int fb_munmap(void *buf, struct fb_fix_screeninfo *scinfo);
+#elif defined(__FreeBSD__)
+static int fb_munmap(void *buf, video_adapter_info_t *video_adapter_info);
+#endif
+#if defined(__linux__)
 static int fb_vscrn_get(int fbfp, struct fb_var_screeninfo *scinfo);
+#endif
+#if defined(__linux__)
 static int fb_cmap_set(int fbfp, struct fb_cmap *cmap);
+#elif defined(__FreeBSD__)
+static int fb_cmap_set(int fbfp, video_color_palette_t *cmap);
+#endif
+#if defined(__linux__)
 static int fb_cmap_get(int fbfp, struct fb_cmap *cmap);
+#elif defined(__FreeBSD__)
+static int fb_cmap_get(int fbfp, video_color_palette_t *cmap);
+#endif
 static int fb_cmap_init(void);
 static int fb_get_cmap_index(int r, int g, int b);
 static unsigned long fb_get_packed_color(int r, int g, int b);
+#if defined(__FreeBSD__)
+static int fb_video_mode_get(int fbfp, int *video_mode);
+static int fb_video_info_get(int fbfp, video_info_t *video_info);
+static int fb_video_adapter_info_get(int fbfp, video_adapter_info_t *video_adapter_info);
+#endif
 
+#if defined(__linux__)
 static struct fb_fix_screeninfo fscinfo;
 static struct fb_var_screeninfo vscinfo;
+#elif defined(__FreeBSD__)
+static video_info_t video_info;
+static video_adapter_info_t video_adapter_info;
+#endif
+#if defined(__linux__)
 static struct fb_cmap *cmap = NULL, *cmap_org = NULL;
+#elif defined(__FreeBSD__)
+static video_color_palette_t *cmap = NULL, *cmap_org = NULL;
+#endif
 static int is_open = FALSE;
 static int fbfp = -1;
 static size_t pixel_size = 0;
@@ -63,6 +118,9 @@
 fb_open(void)
 {
     char *fbdev = { FB_DEFDEV };
+#if defined(__FreeBSD__)
+    int video_mode;
+#endif
 
     if (is_open == TRUE)
 	return 1;
@@ -76,6 +134,7 @@
 	goto ERR_END;
     }
 
+#if defined(__linux__)
     if (fb_fscrn_get(fbfp, &fscinfo)) {
 	goto ERR_END;
     }
@@ -83,22 +142,67 @@
     if (fb_vscrn_get(fbfp, &vscinfo)) {
 	goto ERR_END;
     }
+#elif defined(__FreeBSD__)
+    if (fb_video_mode_get(fbfp, &video_mode)) {
+	goto ERR_END;
+    }
+    video_info.vi_mode = video_mode;
+
+    if (fb_video_info_get(fbfp, &video_info)) {
+	goto ERR_END;
+    }
+
+    if (fb_video_adapter_info_get(fbfp, &video_adapter_info)) {
+	goto ERR_END;
+    }
+    if (!(video_info.vi_flags & V_INFO_GRAPHICS) ||
+	!(video_info.vi_flags & V_INFO_LINEAR)) {
+	goto ERR_END;
+    }
+#endif
 
+#if defined(__linux__)
     if ((cmap = fb_cmap_create(&fscinfo, &vscinfo)) == (struct fb_cmap *)-1) {
 	goto ERR_END;
     }
+#elif defined(__FreeBSD__)
+    if ((cmap = fb_cmap_create(&video_info, &video_adapter_info)) == (video_color_palette_t *)-1) {
+	goto ERR_END;
+    }
+#endif
 
+#if defined(__linux__)
     if (!(buf = fb_mmap(fbfp, &fscinfo))) {
 	fprintf(stderr, "Can't allocate memory.\n");
 	goto ERR_END;
     }
+#elif defined(__FreeBSD__)
+    if (!(buf = fb_mmap(fbfp, &video_adapter_info))) {
+	fprintf(stderr, "Can't allocate memory.\n");
+	goto ERR_END;
+    }
+#endif
 
+#if defined(__linux__)
     if (fscinfo.type != FB_TYPE_PACKED_PIXELS) {
 	fprintf(stderr, "This type of framebuffer is not supported.\n");
 	goto ERR_END;
     }
+#elif defined(__FreeBSD__)
+    if (!(video_info.vi_mem_model == V_INFO_MM_PACKED || 
+	  video_info.vi_mem_model == V_INFO_MM_DIRECT)) {
+	fprintf(stderr, "This type of framebuffer is not supported.\n");
+	goto ERR_END;
+    }
+#endif
 
+#if defined(__linux__)
     if (fscinfo.visual == FB_VISUAL_PSEUDOCOLOR && vscinfo.bits_per_pixel == 8) {
+#elif defined(__FreeBSD__)
+    if (video_adapter_info.va_flags & V_ADP_PALETTE &&
+	video_info.vi_mem_model == V_INFO_MM_PACKED &&
+	video_info.vi_depth == 8) {
+#endif
 	if (fb_cmap_get(fbfp, cmap)) {
 	    fprintf(stderr, "Can't get color map.\n");
 	    fb_cmap_destroy(cmap);
@@ -111,12 +215,20 @@
 
 	pixel_size = 1;
     }
+#if defined(__linux__)
     else if ((fscinfo.visual == FB_VISUAL_TRUECOLOR ||
 	      fscinfo.visual == FB_VISUAL_DIRECTCOLOR) &&
 	     (vscinfo.bits_per_pixel == 15 ||
 	      vscinfo.bits_per_pixel == 16 ||
 	      vscinfo.bits_per_pixel == 24 || vscinfo.bits_per_pixel == 32)) {
 	pixel_size = (vscinfo.bits_per_pixel + 7) / CHAR_BIT;
+#elif defined(__FreeBSD__)
+    else if (video_info.vi_mem_model == V_INFO_MM_DIRECT &&
+	     (video_info.vi_depth == 15 ||
+	      video_info.vi_depth == 16 ||
+	      video_info.vi_depth == 24 || video_info.vi_depth == 32)) {
+	pixel_size = (video_info.vi_depth + 7) / CHAR_BIT;
+#endif
     }
     else {
 	fprintf(stderr, "This type of framebuffer is not supported.\n");
@@ -147,7 +259,11 @@
 	cmap = NULL;
     }
     if (buf != NULL) {
+#if defined(__linux__)
 	fb_munmap(buf, &fscinfo);
+#elif defined(__FreeBSD__)
+	fb_munmap(buf, &video_adapter_info);
+#endif
 	buf = NULL;
     }
 
@@ -259,11 +375,19 @@
     if (y + height > fb_height())
 	height = fb_height() - y;
 
+#if defined(__linux__)
     offset_fb = fscinfo.line_length * y + pixel_size * x;
+#elif defined(__FreeBSD__)
+    offset_fb = video_adapter_info.va_line_width * y + pixel_size * x;
+#endif
     offset_img = image->rowstride * sy + pixel_size * sx;
     for (i = 0; i < height; i++) {
 	memcpy(buf + offset_fb, image->data + offset_img, pixel_size * width);
+#if defined(__linux__)
 	offset_fb += fscinfo.line_length;
+#elif defined(__FreeBSD__)
+	offset_fb += video_adapter_info.va_line_width;
+#endif
 	offset_img += image->rowstride;
     }
 
@@ -336,7 +460,11 @@
     if (is_open != TRUE)
 	return 0;
 
+#if defined(__linux__)
     return vscinfo.xres;
+#elif defined(__FreeBSD__)
+    return video_info.vi_width;
+#endif
 }
 
 int
@@ -345,7 +473,11 @@
     if (is_open != TRUE)
 	return 0;
 
+#if defined(__linux__)
     return vscinfo.yres;
+#elif defined(__FreeBSD__)
+    return video_info.vi_height;
+#endif
 }
 
 int
@@ -369,7 +501,11 @@
 	h = fb_height() - y;
 
     if (tmp == NULL) {
+#if defined(__linux__)
 	tmp = malloc(fscinfo.line_length);
+#elif defined(__FreeBSD__)
+	tmp = malloc(video_adapter_info.va_line_width);
+#endif
 	if (tmp == NULL)
 	    return 1;
     }
@@ -384,10 +520,18 @@
 	gg = g;
 	bb = b;
     }
+#if defined(__linux__)
     offset_fb = fscinfo.line_length * y + pixel_size * x;
+#elif defined(__FreeBSD__)
+    offset_fb = video_adapter_info.va_line_width * y + pixel_size * x;
+#endif
     for (i = 0; i < h; i++) {
 	memcpy(buf + offset_fb, tmp, pixel_size * w);
+#if defined(__linux__)
 	offset_fb += fscinfo.line_length;
+#elif defined(__FreeBSD__)
+	offset_fb += video_adapter_info.va_line_width;
+#endif
     }
     return 0;
 }
@@ -400,11 +544,21 @@
 	return fb_get_cmap_index(r, g, b);
     }
     else {
+#if defined(__linux__)
 	return
 	    ((r >> (CHAR_BIT - vscinfo.red.length)) << vscinfo.red.offset) +
 	    ((g >> (CHAR_BIT - vscinfo.green.length)) << vscinfo.green.
 	     offset) +
 	    ((b >> (CHAR_BIT - vscinfo.blue.length)) << vscinfo.blue.offset);
+#elif defined(__FreeBSD__)
+	return
+	    ((r >> (CHAR_BIT - video_info.vi_pixel_fsizes[0])) <<
+	     video_info.vi_pixel_fields[0]) +
+	    ((g >> (CHAR_BIT - video_info.vi_pixel_fsizes[1])) <<
+	     video_info.vi_pixel_fields[1]) +
+	    ((b >> (CHAR_BIT - video_info.vi_pixel_fsizes[2])) <<
+	     video_info.vi_pixel_fields[2]);
+#endif
     }
 }
 
@@ -433,16 +587,31 @@
     if (cmap == NULL)
 	return 1;
 
+#if defined(__linux__)
     if (cmap->len < COLOR_OFFSET_8BIT + COLORS_8BIT) {
 	fprintf(stderr, "Can't allocate enough color.\n");
 	return 1;
     }
+#elif defined(__FreeBSD__)
+    if (cmap->count < COLOR_OFFSET_8BIT + COLORS_8BIT) {
+	fprintf(stderr, "Can't allocate enough color.\n");
+	return 1;
+    }
+#endif
 
     if (cmap_org == NULL) {
+#if defined(__linux__)
 	if ((cmap_org =
 	     fb_cmap_create(&fscinfo, &vscinfo)) == (struct fb_cmap *)-1) {
 	    return 1;
 	}
+#elif defined(__FreeBSD__)
+	if ((cmap_org =
+	     fb_cmap_create(&video_info, &video_adapter_info)) ==
+	     (video_color_palette_t *)-1) {
+	    return 1;
+	}
+#endif
 
 	if (fb_cmap_get(fbfp, cmap_org)) {
 	    fprintf(stderr, "Can't get color map.\n");
@@ -452,8 +621,13 @@
 	}
     }
 
+#if defined(__linux__)
     cmap->start = MONO_OFFSET_8BIT;
     cmap->len = COLORS_8BIT + COLORS_MONO_8BIT;
+#elif defined(__FreeBSD__)
+    cmap->index = MONO_OFFSET_8BIT;
+    cmap->count = COLORS_8BIT + COLORS_MONO_8BIT;
+#endif
 
     for (lp = 0; lp < COLORS_MONO_8BIT; lp++) {
 	int c;
@@ -506,73 +680,213 @@
 
 #define	LUT_MAX		(256)
 
+#if defined(__linux__)
 static struct fb_cmap *
 fb_cmap_create(struct fb_fix_screeninfo *fscinfo,
 	       struct fb_var_screeninfo *vscinfo)
+#elif defined(__FreeBSD__)
+static video_color_palette_t *
+fb_cmap_create(video_info_t *video_info,
+	       video_adapter_info_t *video_adapter_info)
+#endif
 {
+#if defined(__linux__)
     struct fb_cmap *cmap;
+#elif defined(__FreeBSD__)
+    video_color_palette_t *cmap;
+#endif
     int cmaplen = LUT_MAX;
 
     /* check the existence of colormap */
+#if defined(__linux__)
     if (fscinfo->visual == FB_VISUAL_MONO01 ||
 	fscinfo->visual == FB_VISUAL_MONO10 ||
 	fscinfo->visual == FB_VISUAL_TRUECOLOR)
 	return NULL;
+#elif defined(__FreeBSD__)
+    if (!(video_adapter_info->va_flags & V_ADP_PALETTE))
+	return NULL;
+#endif
 
+#if defined(__linux__)
     cmap = (struct fb_cmap *)malloc(sizeof(struct fb_cmap));
+#elif defined(__FreeBSD__)
+    cmap = (video_color_palette_t *)malloc(sizeof(video_color_palette_t));
+#endif
     if (!cmap) {
 	perror("cmap malloc error\n");
+#if defined(__linux__)
 	return (struct fb_cmap *)-1;
+#elif defined(__FreeBSD__)
+	return (video_color_palette_t *)-1;
+#endif
     }
+#if defined(__linux__)
     memset(cmap, 0, sizeof(struct fb_cmap));
+#elif defined(__FreeBSD__)
+    memset(cmap, 0, sizeof(video_color_palette_t));
+#endif
+
+#if defined(__FreeBSD__)
+    if (video_info->vi_mem_model == V_INFO_MM_PACKED) {
+	cmap->red = (u_char *) malloc(sizeof(u_char) * cmaplen);
+	if (!cmap->red) {
+	    perror("red lut malloc error\n");
+	    return (video_color_palette_t *)-1;
+	}
+	cmap->green = (u_char *) malloc(sizeof(u_char) * cmaplen);
+	if (!cmap->green) {
+	    perror("green lut malloc error\n");
+	    free(cmap->red);
+	    return (video_color_palette_t *)-1;
+	}
+	cmap->blue = (u_char *) malloc(sizeof(u_char) * cmaplen);
+	if (!cmap->blue) {
+	    perror("blue lut malloc error\n");
+	    free(cmap->red);
+	    free(cmap->green);
+	    return (video_color_palette_t *)-1;
+	}
+	cmap->transparent = (u_char *) malloc(sizeof(u_char) * cmaplen);
+	if (!cmap->transparent) {
+	    perror("transparent lut malloc error\n");
+	    free(cmap->red);
+	    free(cmap->green);
+	    free(cmap->blue);
+	    return (video_color_palette_t *)-1;
+	}
+	cmap->count = cmaplen;
+	return cmap;
+    }
+#endif
 
     /* Allocates memory for a colormap */
+#if defined(__linux__)
     if (vscinfo->red.length) {
 	cmap->red = (__u16 *) malloc(sizeof(__u16) * cmaplen);
+#elif defined(__FreeBSD__)
+    if (video_info->vi_pixel_fsizes[0]) {
+	cmap->red = (u_char *) malloc(sizeof(u_char) * cmaplen);
+#endif
 	if (!cmap->red) {
 	    perror("red lut malloc error\n");
+#if defined(__linux__)
 	    return (struct fb_cmap *)-1;
+#elif defined(__FreeBSD__)
+	    return (video_color_palette_t *)-1;
+#endif
 	}
     }
+#if defined(__linux__)
     if (vscinfo->green.length) {
 	cmap->green = (__u16 *) malloc(sizeof(__u16) * cmaplen);
+#elif defined(__FreeBSD__)
+    if (video_info->vi_pixel_fsizes[1]) {
+	cmap->green = (u_char *) malloc(sizeof(u_char) * cmaplen);
+#endif
 	if (!cmap->green) {
+#if defined(__linux__)
 	    if (vscinfo->red.length)
 		free(cmap->red);
+#elif defined(__FreeBSD__)
+	    if (video_info->vi_pixel_fsizes[0])
+		free(cmap->red);
+#endif
 	    perror("green lut malloc error\n");
+#if defined(__linux__)
 	    return (struct fb_cmap *)-1;
+#elif defined(__FreeBSD__)
+	    return (video_color_palette_t *)-1;
+#endif
 	}
     }
+#if defined(__linux__)
     if (vscinfo->blue.length) {
 	cmap->blue = (__u16 *) malloc(sizeof(__u16) * cmaplen);
+#elif defined(__FreeBSD__)
+    if (video_info->vi_pixel_fsizes[2]) {
+	cmap->blue = (u_char *) malloc(sizeof(u_char) * cmaplen);
+#endif
 	if (!cmap->blue) {
+#if defined(__linux__)
 	    if (vscinfo->red.length)
 		free(cmap->red);
+#elif defined(__FreeBSD__)
+	    if (video_info->vi_pixel_fsizes[0])
+		free(cmap->red);
+#endif
+#if defined(__linux__)
 	    if (vscinfo->green.length)
 		free(cmap->green);
+#elif defined(__FreeBSD__)
+	    if (video_info->vi_pixel_fsizes[1])
+		free(cmap->green);
+#endif
 	    perror("blue lut malloc error\n");
+#if defined(__linux__)
 	    return (struct fb_cmap *)-1;
+#elif defined(__FreeBSD__)
+	    return (video_color_palette_t *)-1;
+#endif
 	}
     }
+#if defined(__linux__)
     if (vscinfo->transp.length) {
 	cmap->transp = (__u16 *) malloc(sizeof(__u16) * cmaplen);
+#elif defined(__FreeBSD__)
+    if (video_info->vi_pixel_fsizes[3]) {
+	cmap->transparent = (u_char *) malloc(sizeof(u_char) * cmaplen);
+#endif
+#if defined(__linux__)
 	if (!cmap->transp) {
+#elif defined(__FreeBSD__)
+	if (!cmap->transparent) {
+#endif
+#if defined(__linux__)
 	    if (vscinfo->red.length)
 		free(cmap->red);
+#elif defined(__FreeBSD__)
+	    if (video_info->vi_pixel_fsizes[0])
+		free(cmap->red);
+#endif
+#if defined(__linux__)
 	    if (vscinfo->green.length)
 		free(cmap->green);
+#elif defined(__FreeBSD__)
+	    if (video_info->vi_pixel_fsizes[1])
+		free(cmap->green);
+#endif
+#if defined(__linux__)
 	    if (vscinfo->blue.length)
 		free(cmap->blue);
 	    perror("transp lut malloc error\n");
+#elif defined(__FreeBSD__)
+	    if (video_info->vi_pixel_fsizes[2])
+		free(cmap->blue);
+	    perror("transparent lut malloc error\n");
+#endif
+#if defined(__linux__)
 	    return (struct fb_cmap *)-1;
+#elif defined(__FreeBSD__)
+	    return (video_color_palette_t *)-1;
+#endif
 	}
     }
+#if defined(__linux__)
     cmap->len = cmaplen;
+#elif defined(__FreeBSD__)
+    cmap->count = cmaplen;
+#endif
     return cmap;
 }
 
+#if defined(__linux__)
 static void
 fb_cmap_destroy(struct fb_cmap *cmap)
+#elif defined(__FreeBSD__)
+static void
+fb_cmap_destroy(video_color_palette_t *cmap)
+#endif
 {
     if (cmap->red)
 	free(cmap->red);
@@ -580,28 +894,57 @@
 	free(cmap->green);
     if (cmap->blue)
 	free(cmap->blue);
+#if defined(__linux__)
     if (cmap->transp)
 	free(cmap->transp);
+#elif defined(__FreeBSD__)
+    if (cmap->transparent)
+	free(cmap->transparent);
+#endif
     free(cmap);
 }
 
+#if defined(__linux__)
 static int
 fb_cmap_get(int fbfp, struct fb_cmap *cmap)
+#elif defined(__FreeBSD__)
+static int
+fb_cmap_get(int fbfp, video_color_palette_t *cmap)
+#endif
 {
+#if defined(__linux__)
     if (ioctl(fbfp, FBIOGETCMAP, cmap)) {
 	perror("ioctl FBIOGETCMAP error\n");
 	return -1;
     }
+#elif defined(__FreeBSD__)
+    if (ioctl(fbfp, FBIO_GETPALETTE, cmap) == -1) {
+	perror("ioctl FBIO_GETPALETTE error\n");
+	return -1;
+    }
+#endif
     return 0;
 }
 
+#if defined(__linux__)
 static int
 fb_cmap_set(int fbfp, struct fb_cmap *cmap)
+#elif defined(__FreeBSD__)
+static int
+fb_cmap_set(int fbfp, video_color_palette_t *cmap)
+#endif
 {
+#if defined(__linux__)
     if (ioctl(fbfp, FBIOPUTCMAP, cmap)) {
 	perror("ioctl FBIOPUTCMAP error\n");
 	return -1;
     }
+#elif defined(__FreeBSD__)
+    if (ioctl(fbfp, FBIO_SETPALETTE, cmap) == -1) {
+	perror("ioctl FBIO_SETPALETTE error\n");
+	return -1;
+    }
+#endif
     return 0;
 }
 
@@ -612,10 +955,16 @@
  * fb_munmap()          deletes the mappings
  */
 
+#if defined(__linux__)
 static void *
 fb_mmap(int fbfp, struct fb_fix_screeninfo *scinfo)
+#elif defined(__FreeBSD__)
+static void *
+fb_mmap(int fbfp, video_adapter_info_t *video_adapter_info)
+#endif
 {
     void *buf;
+#if defined(__linux__)
     if ((buf = (unsigned char *)
 	 mmap(NULL, scinfo->smem_len, PROT_READ | PROT_WRITE, MAP_SHARED, fbfp,
 	      (off_t) 0))
@@ -623,13 +972,41 @@
 	perror("mmap error");
 	return NULL;
     }
+#elif defined(__FreeBSD__)
+    size_t mmap_offset;
+    size_t mmap_length;
+    mmap_offset = (size_t)(video_adapter_info->va_window) & (PAGE_MASK);
+    mmap_length = (size_t)(video_adapter_info->va_window_size +
+			   mmap_offset + PAGE_MASK) & (~PAGE_MASK);
+    if ((buf = (unsigned char *)
+	 mmap(NULL, mmap_length, PROT_READ | PROT_WRITE, MAP_SHARED, fbfp,
+	      (off_t) 0))
+	== MAP_FAILED) {
+	perror("mmap error");
+	return NULL;
+    }
+#endif
     return buf;
 }
 
+#if defined(__linux__)
 static int
 fb_munmap(void *buf, struct fb_fix_screeninfo *scinfo)
+#elif defined(__FreeBSD__)
+static int
+fb_munmap(void *buf, video_adapter_info_t *video_adapter_info)
+#endif
 {
+#if defined(__linux__)
     return munmap(buf, scinfo->smem_len);
+#elif defined(__FreeBSD__)
+    size_t mmap_offset;
+    size_t mmap_length;
+    mmap_offset = (size_t)(video_adapter_info->va_window) & (PAGE_MASK);
+    mmap_length = (size_t)(video_adapter_info->va_window_size +
+			   mmap_offset + PAGE_MASK) & (~PAGE_MASK);
+    return munmap((void *)((u_long)buf & (~PAGE_MASK)), mmap_length);
+#endif
 }
 
 /*
@@ -637,6 +1014,7 @@
  * 
  * fb_fscrn_get()               get information
  */
+#if defined(__linux__)
 static int
 fb_fscrn_get(int fbfp, struct fb_fix_screeninfo *scinfo)
 {
@@ -646,12 +1024,14 @@
     }
     return 0;
 }
+#endif
 
 /*
  * (struct fb_var_screeninfo) device independent variable information
  * 
  * fb_vscrn_get()               get information
  */
+#if defined(__linux__)
 static int
 fb_vscrn_get(int fbfp, struct fb_var_screeninfo *scinfo)
 {
@@ -661,3 +1041,41 @@
     }
     return 0;
 }
+#endif
+
+#if defined(__FreeBSD__)
+static int
+fb_video_mode_get(int fbfp, int *video_mode)
+{
+    if (ioctl(fbfp, FBIO_GETMODE, video_mode) == -1) {
+	perror("ioctl FBIO_GETMODE error\n");
+	return -1;
+    }
+    return 0;
+}
+#endif
+
+#if defined(__FreeBSD__)
+static int
+fb_video_info_get(int fbfp, video_info_t *video_info)
+{
+    if (ioctl(fbfp, FBIO_MODEINFO, video_info) == -1) {
+	perror("ioctl FBIO_MODEINFO error\n");
+	return -1;
+    }
+    return 0;
+}
+#endif
+
+#if defined(__FreeBSD__)
+static int
+fb_video_adapter_info_get(int fbfp, video_adapter_info_t *video_adapter_info)
+{
+    if (ioctl(fbfp, FBIO_ADPINFO, video_adapter_info) == -1) {
+	perror("ioctl FBIO_ADPINFO error\n");
+	return -1;
+    }
+    return 0;
+}
+#endif
+
