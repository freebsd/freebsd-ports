--- src/gdevijs.c.orig	2003-01-17 00:49:00 UTC
+++ src/gdevijs.c
@@ -29,15 +29,29 @@
  * which is a security risk, since any program can be run.
  * You should use -dSAFER which sets .LockSafetyParams to true 
  * before opening this device.
+ *
+ * 11/26/03 David Suffield
+ * (c) 2003-2004 Copyright Hewlett-Packard Development Company, LP
+ *
+ * 1. Removed hpijs 1.0-1.0.2 workarounds, use hpijs 1.0.3 or higher.
+ * 2. Added krgb support.
+ *
+ * 02/21/05 David Suffield
+ * 1. Fixed segfault issue with 1-bit color space.
+ * 2. Fixed z-order issue with colored text on black rectangle.
+ *
  */
 
 #include "unistd_.h"	/* for dup() */
 #include <stdlib.h>
+#include <fcntl.h>
 #include "gdevprn.h"
 #include "gp.h"
 #include "ijs.h"
 #include "ijs_client.h"
 
+//#define KRGB_DEBUG
+
 /* This should go into gdevprn.h, or, better yet, gdevprn should
    acquire an API for changing resolution. */
 int gdev_prn_maybe_realloc_memory(gx_device_printer *pdev,
@@ -53,6 +67,14 @@ private dev_proc_output_page(gsijs_outpu
 private dev_proc_get_params(gsijs_get_params);
 private dev_proc_put_params(gsijs_put_params);
 
+/* Following definitions are for krgb support. */
+private dev_proc_create_buf_device(gsijs_create_buf_device);
+private dev_proc_fill_rectangle(gsijs_fill_rectangle);
+private dev_proc_copy_mono(gsijs_copy_mono);
+private dev_proc_fill_mask(gsijs_fill_mask);
+private dev_proc_fill_path(gsijs_fill_path);
+private dev_proc_stroke_path(gsijs_stroke_path);
+
 private const gx_device_procs gsijs_procs =
 prn_color_params_procs(gsijs_open, gsijs_output_page, gsijs_close,
 		   gx_default_rgb_map_rgb_color, gx_default_rgb_map_color_rgb,
@@ -85,6 +107,14 @@ struct gx_device_ijs_s {
 
     IjsClientCtx *ctx;
     int ijs_version;
+
+    /* Additional parameters for krgb support. */
+    int krgb_mode;     /* 0=false, 1=true */
+    int k_path;        /* k plane path, 0=false, 1=true */
+    int k_width;       /* k plane width in pixels */
+    int k_band_size;   /* k plane buffer size in bytes, byte aligned */
+    unsigned char *k_band;  /* k plane buffer */
+    gx_device_procs prn_procs;  /* banding playback procedures */
 };
 
 #define DEFAULT_DPI 74   /* See gsijs_set_resolution() below. */
@@ -112,7 +142,12 @@ gx_device_ijs gs_ijs_device =
     FALSE,	/* Tumble_set */
 
     NULL,	/* IjsClient *ctx */
-    0		/* ijs_version */
+    0,		/* ijs_version */
+    0,          /* krgb_mode */
+    0,          /* k_path */
+    0,          /* k_width */
+    0,          /* k_band_size */
+    NULL        /* k_band buffer */
 };
 
 
@@ -128,12 +163,254 @@ private int gsijs_read_string(gs_param_l
 
 /**************************************************************************/
 
-/* ------ Private definitions ------ */
+/* ---------------- Low-level graphic procedures ---------------- */
 
-/* Versions 1.0 through 1.0.2 of hpijs report IJS version 0.29, and
-   require some workarounds. When more up-to-date hpijs versions
-   become ubiquitous, all these workarounds should be removed. */
-#define HPIJS_1_0_VERSION 29
+static unsigned char xmask[] =
+{
+   0x80,    /* x=0 */
+   0x40,    /* 1 */
+   0x20,    /* 2 */
+   0x10,    /* 3 */
+   0x08,    /* 4 */
+   0x04,    /* 5 */
+   0x02,    /* 6 */
+   0x01     /* 7 */
+};
+
+private int gsijs_fill_rectangle(gx_device * dev, int x, int y, int w, int h,
+           gx_color_index color)
+{
+   gx_device_ijs *ijsdev = (gx_device_ijs *)((gx_device_forward *)dev)->target;
+
+   if (ijsdev->krgb_mode && ijsdev->k_path && y >= 0 && x >= 0) 
+   {
+      int raster = (ijsdev->k_width+7) >> 3;
+      register unsigned char *dest=ijsdev->k_band+(raster*y)+(x >> 3);
+      int dest_start_bit = x & 7;
+      int i,j,w1;
+
+      if (h <= 0 || w <= 0)
+         return 0;
+
+      if ((x+w) > ijsdev->k_width)
+         w1 = ijsdev->k_width - x; 
+      else
+         w1 = w;
+
+      /* Note x,y orgin 0,0 is stored first byte 0 left to right. */
+
+      if (color==0x0)
+      { 
+         /* Color is black, store in k plane band instead of regular band. */
+         for (j=0; j<h; j++)
+         {
+            for (i=0; i<w1; i++)
+               dest[(dest_start_bit+i)>>3] |= xmask[(dest_start_bit+i)&7];
+            dest+=raster;    
+         }
+         return 0;
+      }
+      else
+      {
+         /* Color is not black, remove any k plane bits for z-order dependencies, store in regular band. */
+         for (j=0; j<h; j++)
+         {
+            for (i=0; i<w1; i++)
+               dest[(dest_start_bit+i)>>3] &= ~xmask[(dest_start_bit+i)&7];
+            dest+=raster;    
+         }
+      }
+   }
+
+   return (*ijsdev->prn_procs.fill_rectangle)(dev, x, y, w, h, color);
+}
+
+private int gsijs_copy_mono(gx_device * dev, const byte * data,
+      int dx, int draster, gx_bitmap_id id,
+      int x, int y, int w, int height, gx_color_index zero, gx_color_index one)
+{
+   gx_device_ijs *ijsdev = (gx_device_ijs *)((gx_device_forward *)dev)->target;
+
+   //   if (ijsdev->krgb_mode && ijsdev->k_path && one==0x0) 
+   if (ijsdev->krgb_mode && ijsdev->k_path) 
+   {
+      /* Store in k plane band instead of regular band. */
+      int raster = (ijsdev->k_width+7) >> 3;       /* raster width in bytes, byte aligned */
+      register unsigned char *dest=ijsdev->k_band+(raster*y)+(x >> 3);
+      register const unsigned char *scan=data+(dx >> 3);
+      int dest_start_bit = x & 7;
+      int scan_start_bit = dx & 7;
+      int i, h=height;
+      
+      if (h <= 0 || w <= 0)
+         return 0;
+
+      if (one==0x0)
+      {
+         /* Color is black, store in k plane band instead of regular band. */
+         while (h-- > 0)
+         {
+            for (i=0; i<w; i++)
+            {
+               if (scan[(scan_start_bit+i)>>3] & xmask[(scan_start_bit+i)&7])
+                  dest[(dest_start_bit+i)>>3] |= xmask[(dest_start_bit+i)&7];
+            }
+            scan+=draster;
+            dest+=raster;
+         }
+         return 0;
+      }
+      else
+      {
+         /* Color is not black, remove any k plane bits for z-order dependencies, store in regular band. */
+         while (h-- > 0)
+         {
+            for (i=0; i<w; i++)
+            {
+               if (scan[(scan_start_bit+i)>>3] & xmask[(scan_start_bit+i)&7])
+                  dest[(dest_start_bit+i)>>3] &= ~xmask[(dest_start_bit+i)&7];
+            }
+            scan+=draster;
+            dest+=raster;
+         }
+      }   
+   }
+
+   return (*ijsdev->prn_procs.copy_mono)(dev, data, dx, draster, id, x, y, w, height, zero, one);
+}
+
+/* ---------------- High-level graphic procedures ---------------- */
+
+private int gsijs_fill_mask(gx_device * dev,
+      const byte * data, int dx, int raster, gx_bitmap_id id,
+      int x, int y, int w, int h,
+      const gx_drawing_color * pdcolor, int depth,
+      gs_logical_operation_t lop, const gx_clip_path * pcpath)
+{
+   gx_device_ijs *ijsdev = (gx_device_ijs *)((gx_device_forward *)dev)->target;
+   int code;
+
+   ijsdev->k_path = 1;
+
+   code = (*ijsdev->prn_procs.fill_mask)(dev, data, dx, raster, id, x, y, w, h, pdcolor, depth, lop, pcpath);
+
+   ijsdev->k_path = 0;
+
+   return code;
+}
+
+private int gsijs_fill_path(gx_device * dev, const gs_imager_state * pis,
+      gx_path * ppath, const gx_fill_params * params,
+      const gx_drawing_color * pdcolor,
+      const gx_clip_path * pcpath)
+{
+   gx_device_ijs *ijsdev = (gx_device_ijs *)((gx_device_forward *)dev)->target;
+   int code;
+
+   ijsdev->k_path = 1;
+
+   code = (*ijsdev->prn_procs.fill_path)(dev, pis, ppath, params, pdcolor, pcpath);
+
+   ijsdev->k_path = 0;
+
+   return 0;
+}
+
+private int gsijs_stroke_path(gx_device * dev, const gs_imager_state * pis,
+        gx_path * ppath, const gx_stroke_params * params,
+        const gx_drawing_color * pdcolor,
+        const gx_clip_path * pcpath)
+{
+   gx_device_ijs *ijsdev = (gx_device_ijs *)((gx_device_forward *)dev)->target;
+   int code;
+
+   ijsdev->k_path = 1;
+
+   code = (*ijsdev->prn_procs.stroke_path)(dev, pis, ppath, params, pdcolor, pcpath);
+
+   ijsdev->k_path = 0;
+
+   return code;
+}
+
+/* ---------------- krgb banding playback procedures ---------------- */
+
+private int gsijs_get_bits(gx_device_printer * pdev, int y, byte * str, byte ** actual_data)
+{
+   gx_device_ijs *ijsdev = (gx_device_ijs *)pdev;
+   gx_device_clist_common *cdev = (gx_device_clist_common *)pdev;
+   int band_height = cdev->page_info.band_params.BandHeight;
+   int band_number = y/band_height;
+   int raster = (ijsdev->k_width+7) >> 3;       /* raster width in bytes, byte aligned */
+   int y1=raster*(y-(band_height*band_number));
+ 
+   if (y1 == 0)
+   {
+      /* First raster for band, clear k_band. Banding playback occurs on first raster. */
+      memset(ijsdev->k_band, 0, ijsdev->k_band_size); 
+   }
+
+   return gdev_prn_get_bits(pdev, y, str, actual_data);  /* get raster from regular band */
+}
+
+private int gsijs_k_get_bits(gx_device_printer * pdev, int y, byte ** actual_data)
+{
+   gx_device_ijs *ijsdev = (gx_device_ijs *)pdev;
+   gx_device_clist_common *cdev = (gx_device_clist_common *)pdev;
+   int band_height = cdev->page_info.band_params.BandHeight;
+   int band_number = y/band_height;
+   int raster = (ijsdev->k_width+7) >> 3;       /* raster width in bytes, byte aligned */
+   int y1=raster*(y-(band_height*band_number));
+ 
+   *actual_data = ijsdev->k_band+y1;
+
+   return 0;
+}
+
+private int gsijs_create_buf_device(gx_device **pbdev, gx_device *target,
+            const gx_render_plane_t *render_plane, gs_memory_t *mem, bool for_band)
+{
+   gx_device_ijs *ijsdev = (gx_device_ijs *)target;
+   int n_chan = ijsdev->color_info.num_components;
+   int code = gx_default_create_buf_device(pbdev, target, render_plane, mem, for_band);
+   if (code < 0 || n_chan != 3)
+      return code;
+
+   /* Save buffer (vector) procedures so that we can hook them during banding playback. */
+   ijsdev->prn_procs = (*pbdev)->procs;
+
+   /* Replace buffer procedures with krgb procedures. */
+   set_dev_proc(*pbdev, fill_rectangle, gsijs_fill_rectangle);
+   set_dev_proc(*pbdev, copy_mono, gsijs_copy_mono);
+   set_dev_proc(*pbdev, fill_mask, gsijs_fill_mask);
+   set_dev_proc(*pbdev, fill_path, gsijs_fill_path);
+   set_dev_proc(*pbdev, stroke_path, gsijs_stroke_path);
+
+   return code;
+}
+
+/* See if IJS server supports krgb. Return value: 0=false, 1=true. */
+private int
+gsijs_set_krgb_mode(gx_device_ijs *ijsdev)
+{
+    char buf[256];
+    int n_chan = ijsdev->color_info.num_components;
+    int code;
+
+    if (n_chan != 3)
+        return 0;    /* no krgb support, not RGB colorspace */
+
+    buf[0] = 0;
+    code = ijs_client_enum_param(ijsdev->ctx, 0, "ColorSpace", buf, sizeof(buf)-1);
+    if (code >= 0)
+        buf[code] = 0;
+    if (strstr(buf, "KRGB") == NULL)
+        return 0;  /* no krgb support */
+
+    return 1;  /* krgb is supported */
+}
+
+/* ------ Private definitions ------ */
 
 private int
 gsijs_parse_wxh (const char *val, int size, double *pw, double *ph)
@@ -171,34 +448,6 @@ gsijs_parse_wxh (const char *val, int si
 }
 
 /**
- * gsijs_set_generic_params_hpijs: Set generic IJS parameters.
- *
- * This version is specialized for hpijs 1.0 through 1.0.2, and
- * accommodates a number of quirks.
- **/
-private int
-gsijs_set_generic_params_hpijs(gx_device_ijs *ijsdev)
-{
-    char buf[256];
-    int code = 0;
-
-    /* IjsParams, Duplex, and Tumble get set at this point because
-       they may affect margins. */
-    if (ijsdev->IjsParams) {
-	code = gsijs_client_set_param(ijsdev, "IjsParams", ijsdev->IjsParams);
-    }
-
-    if (code == 0 && ijsdev->Duplex_set) {
-	int duplex_val;
-	
-	duplex_val = ijsdev->Duplex ? (ijsdev->IjsTumble ? 1 : 2) : 0;
-	sprintf (buf, "%d", duplex_val);
-	code = gsijs_client_set_param(ijsdev, "Duplex", buf);
-    }
-    return code;
-}
-
-/**
  * gsijs_set_generic_params: Set generic IJS parameters.
  **/
 private int
@@ -209,9 +458,6 @@ gsijs_set_generic_params(gx_device_ijs *
     int i, j;
     char *value;
 
-    if (ijsdev->ijs_version == HPIJS_1_0_VERSION)
-	return gsijs_set_generic_params_hpijs(ijsdev);
-
     /* Split IjsParams into separate parameters and send to ijs server */
     value = NULL;
     for (i=0, j=0; (j < ijsdev->IjsParams_size) && (i < sizeof(buf)-1); j++) {
@@ -252,68 +498,6 @@ gsijs_set_generic_params(gx_device_ijs *
 }
 
 /**
- * gsijs_set_margin_params_hpijs: Do margin negotiation with IJS server.
- *
- * This version is specialized for hpijs 1.0 through 1.0.2, and
- * accommodates a number of quirks.
- **/
-private int
-gsijs_set_margin_params_hpijs(gx_device_ijs *ijsdev)
-{
-    char buf[256];
-    int code = 0;
-
-    if (code == 0) {
-	sprintf(buf, "%d", ijsdev->width);
-	code = gsijs_client_set_param(ijsdev, "Width", buf);
-    }
-    if (code == 0) {
-	sprintf(buf, "%d", ijsdev->height);
-	code = gsijs_client_set_param(ijsdev, "Height", buf);
-    }
-
-    if (code == 0) {
-	double printable_width, printable_height;
-	double printable_left, printable_top;
-	float m[4];
-
-	code = ijs_client_get_param(ijsdev->ctx, 0, "PrintableArea",
-				   buf, sizeof(buf));
-	if (code == IJS_EUNKPARAM)
-	    /* IJS server doesn't support margin negotiations.
-	       That's ok. */
-	    return 0;
-	else if (code >= 0) {
-	    code = gsijs_parse_wxh(buf, code,
-				    &printable_width, &printable_height);
-	}
-
-	if (code == 0) {
-	    code = ijs_client_get_param(ijsdev->ctx, 0, "PrintableTopLeft",
-					buf, sizeof(buf));
-	    if (code == IJS_EUNKPARAM)
-		return 0;
-	    else if (code >= 0) {
-		code = gsijs_parse_wxh(buf, code,
-					&printable_left, &printable_top);
-	    }
-	}
-
-	if (code == 0) {
-	    m[0] = printable_left;
-	    m[1] = ijsdev->MediaSize[1] * (1.0 / 72) -
-	      printable_top - printable_height;
-	    m[2] = ijsdev->MediaSize[0] * (1.0 / 72) -
-	      printable_left - printable_width;
-	    m[3] = printable_top;
-	    gx_device_set_margins((gx_device *)ijsdev, m, true);
-	}
-    }
-
-    return code;
-}
-
-/**
  * gsijs_set_margin_params: Do margin negotiation with IJS server.
  **/
 private int
@@ -324,9 +508,6 @@ gsijs_set_margin_params(gx_device_ijs *i
     int i, j;
     char *value;
 
-    if (ijsdev->ijs_version == HPIJS_1_0_VERSION)
-	return gsijs_set_margin_params_hpijs(ijsdev);
-
     /* Split IjsParams into separate parameters and send to ijs server */
     value = NULL;
     for (i=0, j=0; (j < ijsdev->IjsParams_size) && (i < sizeof(buf)-1); j++) {
@@ -493,12 +674,18 @@ gsijs_open(gx_device *dev)
     char buf[256];
     bool use_outputfd;
     int fd = -1;
+    long max_bitmap = ijsdev->space_params.MaxBitmap;
 
     if (strlen(ijsdev->IjsServer) == 0) {
 	eprintf("ijs server not specified\n");
 	return gs_note_error(gs_error_ioerror);
     }
 
+    ijsdev->space_params.MaxBitmap = 0;	/* force banding */
+
+    /* Set create_buf_device in printer device, so that we can hook the banding playback procedures. */
+    ijsdev->printer_procs.buf_procs.create_buf_device = gsijs_create_buf_device;
+
     /* Decide whether to use OutputFile or OutputFD. Note: how to
        determine this is a tricky question, so we just allow the
        user to set it.
@@ -513,6 +700,8 @@ gsijs_open(gx_device *dev)
     if (code < 0)
 	return code;
 
+    ijsdev->space_params.MaxBitmap = max_bitmap;
+    
     if (use_outputfd) {
 	/* Note: dup() may not be portable to all interesting IJS
 	   platforms. In that case, this branch should be #ifdef'ed out.
@@ -572,6 +761,9 @@ gsijs_open(gx_device *dev)
     if (code >= 0)
 	code = gsijs_set_margin_params(ijsdev);
 
+    if (code >= 0)
+        ijsdev->krgb_mode = gsijs_set_krgb_mode(ijsdev);
+
     return code;
 };
 
@@ -631,21 +823,6 @@ gsijs_raster_width(gx_device *pdev)
     return min(width, end);
 }
 
-private int ijs_all_white(unsigned char *data, int size)
-{
-   int clean = 1;
-   int i;
-   for (i = 0; i < size; i++)
-   {
-     if (data[i] != 0xFF)
-     {
-        clean = 0;
-        break;
-     }
-   }
-   return clean;
-}
-
 /* Print a page.  Don't use normal printer gdev_prn_output_page 
  * because it opens the output file.
  */
@@ -656,8 +833,9 @@ gsijs_output_page(gx_device *dev, int nu
     gx_device_printer *pdev = (gx_device_printer *)dev;
     int raster = gdev_prn_raster(pdev);
     int ijs_width, ijs_height;
-    int row_bytes;
+    int row_bytes, k_row_bytes=0;
     int n_chan = pdev->color_info.num_components;
+    int krgb_mode = ijsdev->krgb_mode;
     unsigned char *data;
     char buf[256];
     double xres = pdev->HWResolution[0];
@@ -673,13 +851,23 @@ gsijs_output_page(gx_device *dev, int nu
 
     /* Determine bitmap width and height */
     ijs_height = gdev_prn_print_scan_lines(dev);
-    if (ijsdev->ijs_version == HPIJS_1_0_VERSION) {
-	ijs_width = pdev->width;
-    } else {
 	ijs_width = gsijs_raster_width(dev);
-    }
+
     row_bytes = (ijs_width * pdev->color_info.depth + 7) >> 3;
 
+    if (krgb_mode)
+    {
+        gx_device_clist_common *cdev = (gx_device_clist_common *)dev;
+        int band_height = cdev->page_info.band_params.BandHeight;
+        k_row_bytes = (ijs_width + 7) >> 3;
+
+        /* Create banding buffer for k plane. */
+        ijsdev->k_width = ijs_width;
+        ijsdev->k_band_size = band_height * k_row_bytes;   
+        if ((ijsdev->k_band = gs_malloc(ijsdev->k_band_size, 1, "gsijs_output_page")) == (unsigned char *)NULL)
+           return gs_note_error(gs_error_VMerror);
+    }
+
     /* Required page parameters */
     sprintf(buf, "%d", n_chan);
     gsijs_client_set_param(ijsdev, "NumChan", buf);
@@ -688,44 +876,71 @@ gsijs_output_page(gx_device *dev, int nu
 
     /* This needs to become more sophisticated for DeviceN. */
     strcpy(buf, (n_chan == 4) ? "DeviceCMYK" : 
-	((n_chan == 3) ? "DeviceRGB" : "DeviceGray"));
+	((n_chan == 3) ? (krgb_mode ? "KRGB" : "DeviceRGB") : "DeviceGray"));
     gsijs_client_set_param(ijsdev, "ColorSpace", buf);
 
-    /* If hpijs 1.0, don't set width and height here, because it
-       expects them to be the paper size. */
-    if (ijsdev->ijs_version != HPIJS_1_0_VERSION) {
-	sprintf(buf, "%d", ijs_width);
-	gsijs_client_set_param(ijsdev, "Width", buf);
-	sprintf(buf, "%d", ijs_height);
-	gsijs_client_set_param(ijsdev, "Height", buf);
-    }
+    sprintf(buf, "%d", ijs_width);
+    gsijs_client_set_param(ijsdev, "Width", buf);
+    sprintf(buf, "%d", ijs_height);
+    gsijs_client_set_param(ijsdev, "Height", buf);
 
     sprintf(buf, "%gx%g", xres, yres);
     gsijs_client_set_param(ijsdev, "Dpi", buf);
 
+#ifdef KRGB_DEBUG
+    int kfd, rgbfd;
+    char sz[128];
+    kfd = open("/tmp/k.pbm", O_CREAT | O_TRUNC | O_RDWR, 0644);
+    rgbfd = open("/tmp/rgb.ppm", O_CREAT | O_TRUNC | O_RDWR, 0644);
+    snprintf(sz, sizeof(sz), "P4\n#gdevijs test\n%d\n%d\n", ijs_width, ijs_height);
+    write(kfd, sz, strlen(sz));
+    snprintf(sz, sizeof(sz), "P6\n#gdevijs test\n%d\n%d\n255\n", ijs_width, ijs_height);
+    write(rgbfd, sz, strlen(sz));
+#endif
+
     for (i=0; i<num_copies; i++) {
  	unsigned char *actual_data;
 	ijs_client_begin_cmd (ijsdev->ctx, IJS_CMD_BEGIN_PAGE);
 	status = ijs_client_send_cmd_wait(ijsdev->ctx);
 
 	for (y = 0; y < ijs_height; y++) {
-	    code = gdev_prn_get_bits(pdev, y, data, &actual_data);
-	    if (code < 0)
-		break;
+            if (krgb_mode)
+                code = gsijs_get_bits(pdev, y, data, &actual_data);
+            else
+                code = gdev_prn_get_bits(pdev, y, data, &actual_data);
+            if (code < 0)
+                break;
+#ifdef KRGB_DEBUG
+            write(rgbfd, actual_data, row_bytes);
+#endif
+            status = ijs_client_send_data_wait(ijsdev->ctx, 0, (char *)actual_data, row_bytes);
+            if (status)
+                break;
 
-	    if (ijsdev->ijs_version == HPIJS_1_0_VERSION &&
-		ijs_all_white(actual_data, row_bytes))
-		status = ijs_client_send_data_wait(ijsdev->ctx, 0, NULL, 0);
-	    else
-		status = ijs_client_send_data_wait(ijsdev->ctx, 0,
-		    (char *)actual_data, row_bytes);
-	    if (status)
-		break;
+            if (krgb_mode) {
+                code = gsijs_k_get_bits(pdev, y, &actual_data);
+                if (code < 0)
+                    break;
+#ifdef KRGB_DEBUG
+                write(kfd, actual_data, k_row_bytes);
+#endif
+                status = ijs_client_send_data_wait(ijsdev->ctx, 0, (char *)actual_data, k_row_bytes);
+                if (status)
+                    break;
+	    }
 	}
 	ijs_client_begin_cmd(ijsdev->ctx, IJS_CMD_END_PAGE);
 	status = ijs_client_send_cmd_wait(ijsdev->ctx);
     }
 
+#ifdef KRGB_DEBUG
+    close(kfd);
+    close(rgbfd);
+#endif
+
+    if(krgb_mode)
+        gs_free(ijsdev->k_band, ijsdev->k_band_size, 1, "gsijs_output_page");
+
     gs_free_object(pdev->memory, data, "gsijs_output_page");
 
     endcode = (pdev->buffer_space && !pdev->is_async_renderer ?
@@ -1029,7 +1244,6 @@ gsijs_client_set_param(gx_device_ijs *ij
 	dprintf2("ijs: Can't set parameter %s=%s\n", key, value);
     return code;
 }
- 
 
 private int
 gsijs_set_color_format(gx_device_ijs *ijsdev)
