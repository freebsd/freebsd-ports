--- src/gdevmjc.c.orig	Tue May 23 19:16:52 2000
+++ src/gdevmjc.c	Tue May 23 19:17:44 2000
@@ -43,7 +43,8 @@
 #include <limits.h>
 #include "gdevprn.h"
 #include "gdevpcl.h"
-#include "gsprops.h"
+#include "gsparam.h"
+#include "gsstate.h"
 
 #include "mjmtx2.c"
 #include "mjbksep.c"
@@ -150,7 +151,9 @@
 
 /* Undefined macros expected to be defined in gdevpcl.h */
 #define PAPER_SIZE_A3_NOBI 28
+#ifndef PAPER_SIZE_A2
 #define PAPER_SIZE_A2 29
+#endif
 #define PAPER_SIZE_B4 30
 #define PAPER_SIZE_B5 31
 
@@ -190,14 +193,12 @@
 private dev_proc_print_page(mjc720_print_page);
 private dev_proc_print_page(mj500c_print_page);
 
-private dev_proc_get_props(mj_get_props);
-private dev_proc_put_props(mj_put_props);
+private dev_proc_get_params(mj_get_params);
+private dev_proc_put_params(mj_put_params);
 
 private void expand_line(P4(word*, int, int, int));
-private int put_prop_float(P5(gs_prop_item *, float *, float, float, int));
-private int put_prop_int(P5(gs_prop_item *, int *, int, int, int));
-
-private void set_bpp(P2(gx_device *, int));
+private int mj_put_param_int(P6(gs_param_list *, gs_param_name, int *, int, int, int));
+private void mj_set_bpp(P2(gx_device *, int));
 
 private uint gdev_prn_rasterwidth(P2(const gx_device_printer *, int ));
 
@@ -224,7 +225,7 @@
 #define mj    ((gx_device_mj *) pdev)
 
 #define prn_hp_colour_device(procs, dev_name, x_dpi, y_dpi, bpp, print_page)\
-    prn_device_body(gx_device_printer, procs, dev_name,\
+    prn_device_body(gx_device_mj, procs, dev_name,\
     WIDTH_10THS, HEIGHT_10THS, x_dpi, y_dpi, 0, 0, 0, 0, 0,\
     bpp, 0, 0, 0, 0, print_page)
 
@@ -235,9 +236,9 @@
 }
 
 
-#define mj_colour_procs(proc_colour_open, proc_get_props, proc_put_props) {\
+#define mj_colour_procs(proc_colour_open, proc_get_params, proc_put_params) {\
 	proc_colour_open,\
-	gdev_pcl_get_initial_matrix,\
+	gx_default_get_initial_matrix,\
 	gx_default_sync_output,\
 	gdev_prn_output_page,\
 	gdev_prn_close,\
@@ -249,15 +250,15 @@
 	NULL,	/* copy_color */\
 	NULL,	/* draw_line */\
 	gx_default_get_bits,\
-	proc_get_props,\
-	proc_put_props\
+	proc_get_params,\
+	proc_put_params\
 }
 
 private int mjc_open(P1(gx_device *));
 private int mj_colour_open(P1(gx_device *));
 
 private gx_device_procs mj_procs =
-mj_colour_procs(mjc_open, mj_get_props, mj_put_props);
+mj_colour_procs(mjc_open, mj_get_params, mj_put_params);
 
 gx_device_mj far_data gs_mjc180_device =
 mj_device(mj_procs, "mjc180", 180, 180, BITSPERPIXEL,
@@ -306,14 +307,14 @@
   static const float mj_b4[4] = { MJ700V2C_MARGINS_B4 };
   static const float mj_b5[4] = { MJ700V2C_MARGINS_B5 };
   static const float mj_letter[4] = { MJ700V2C_MARGINS_LETTER };
-  const float _ds *m;
+  const float *m;
   int psize;
 
   int paper_size;
 
   /* Set up colour params if put_props has not already done so */
   if (pdev->color_info.num_components == 0)
-    set_bpp(pdev, pdev->color_info.depth);
+    mj_set_bpp(pdev, pdev->color_info.depth);
 
   paper_size = gdev_mjc_paper_size(pdev);
   if (paper_size == PAPER_SIZE_A2 ) {
@@ -332,10 +333,7 @@
     m = mj_letter;
   }
 
-  pdev->l_margin = m[0];
-  pdev->b_margin = m[1];
-  pdev->r_margin = m[2];
-  pdev->t_margin = m[3];
+  gx_device_set_margins(pdev, m, true);
 
   switch (mj->colorcomp) {
   case 1:
@@ -360,80 +358,74 @@
  * and control over the bits-per-pixel used in output rendering */
 /* Added properties for DeskJet 5xxC */
 
-private const gs_prop_item props_mj[] = {
-  /* Read-write properties. */
-  prop_def("Density", prt_int),
-  prop_def("Cyan", prt_int),
-  prop_def("Magenta", prt_int),
-  prop_def("Yellow", prt_int),
-  prop_def("Black", prt_int),
-  prop_def("Dither", prt_int),
-  prop_def("ColorComponent", prt_int),
-  prop_def("Direction", prt_int),
-  prop_def("MicroWeave", prt_int),
-  prop_def("DotSize", prt_int),
-};
-
 private int
-mj_get_props(gx_device *pdev, gs_prop_item *plist)
-{	int start = gdev_prn_get_props(pdev, plist);
-	if ( plist != 0 ) {
-		register gs_prop_item *pi = plist + start;
-		memcpy(pi, props_mj, sizeof(props_mj));
-		pi[0].value.i = mj->density;
-		pi[1].value.i = mj->cyan;
-		pi[2].value.i = mj->magenta;
-		pi[3].value.i = mj->yellow;
-		pi[4].value.i = mj->black;
-		pi[5].value.i = mj->dither;
- 		pi[6].value.i = mj->colorcomp;
-		pi[7].value.i = mj->direction;
-		pi[8].value.i = mj->microweave;
-		pi[9].value.i = mj->dotsize;
-	}
-	return start + sizeof(props_mj) / sizeof(gs_prop_item);
+mj_get_params(gx_device *pdev, gs_param_list *plist)
+{	int code = gdev_prn_get_params(pdev, plist);
+	if ( code < 0 ||
+	    (code = param_write_int(plist, "Density", &mj->density)) < 0 ||
+	    (code = param_write_int(plist, "Cyan", &mj->cyan)) < 0 ||
+	    (code = param_write_int(plist, "Magenta", &mj->magenta)) < 0 ||
+	    (code = param_write_int(plist, "Yellow", &mj->yellow)) < 0 ||
+	    (code = param_write_int(plist, "Black", &mj->black)) < 0 ||
+	    (code = param_write_int(plist, "Dither", &mj->dither)) < 0 ||
+	    (code = param_write_int(plist, "ColorComponent", &mj->colorcomp)) < 0 ||
+	    (code = param_write_int(plist, "Direction", &mj->direction)) < 0 ||
+	    (code = param_write_int(plist, "MicroWeave", &mj->microweave)) < 0 ||
+	    (code = param_write_int(plist, "DotSize", &mj->dotsize)) < 0
+	   )
+	  return code;
+	return code;
 }
 
 /* Put properties. */
 private int
-mj_put_props(gx_device *pdev,  gs_prop_item *plist,  int count)
+mj_put_params(gx_device *pdev, gs_param_list *plist)
 {
-	static const argn = 10;
-/* 	gs_prop_item *known[argn]; */
- 	gs_prop_item *known[10];
 	int old_bpp = mj->color_info.depth;
 	int bpp = 0;
 	int code = 0;
-
-	props_extract(plist, count, props_mj, argn, known, 0);
-	code = gdev_prn_put_props(pdev, plist, count);
-	if ( code < 0 ) return code;
-
-	code = put_prop_int(known[0], &mj->density, 0, INT_MAX, code);
-	code = put_prop_int(known[1], &mj->cyan, 0, INT_MAX, code);
-	code = put_prop_int(known[2], &mj->magenta, 0, INT_MAX, code);
-	code = put_prop_int(known[3], &mj->yellow, 0, INT_MAX, code);
-	code = put_prop_int(known[4], &mj->black, 0, INT_MAX, code);
-	code = put_prop_int(known[5], &mj->dither, 0, 1, code);
- 	code = put_prop_int(known[6], &mj->colorcomp, 1, 4, code);
-	code = put_prop_int(known[7], &mj->direction, 1, 2, code);
-	code = put_prop_int(known[8], &mj->microweave, 0, 1, code);
-	code = put_prop_int(known[9], &mj->dotsize, 0, 1, code);
-
+	int density = mj->density;
+	int cyan = mj->cyan;
+	int magenta = mj->magenta;
+	int yellow = mj->yellow;
+	int black = mj->black;
+	int dither = mj->dither;
+	int colorcomp = mj->colorcomp;
+	int direction = mj->direction;
+	int microweave = mj->microweave;
+	int dotsize = mj->dotsize;
+	code = mj_put_param_int(plist, "Density", &density, 0, INT_MAX, code);
+	code = mj_put_param_int(plist, "Cyan", &cyan, 0, INT_MAX, code);
+	code = mj_put_param_int(plist, "Magenta", &magenta, 0, INT_MAX, code);
+	code = mj_put_param_int(plist, "Yellow", &yellow, 0, INT_MAX, code);
+	code = mj_put_param_int(plist, "Black", &black, 0, INT_MAX, code);
+	code = mj_put_param_int(plist, "Dither", &dither, 0, 1, code);
+	code = mj_put_param_int(plist, "ColorComponent", &colorcomp, 1, 4, code);
+	code = mj_put_param_int(plist, "Direction", &direction, 1, 2, code);
+	code = mj_put_param_int(plist, "MicroWeave", &microweave, 0, 1, code);
+	code = mj_put_param_int(plist, "DotSize", &dotsize, 0, 1, code);
+	code = mj_put_param_int(plist, "BitsPerPixel", &bpp, 1, 32, code);
 	if ( code < 0 )
-	  return_error(code);
-
-	if (bpp != 0) {
-	  set_bpp(pdev, bpp);
-	  
-	  /* Close the device; gs_putdeviceprops will reopen it. */
+	  return code;
+	mj->density = density;
+	mj->cyan = cyan;
+	mj->magenta = magenta;
+	mj->yellow = yellow;
+	mj->black = black;
+	mj->dither = dither;
+	mj->colorcomp = colorcomp;
+	mj->direction = direction;
+	mj->microweave = microweave;
+	mj->dotsize = dotsize;
+	if ( bpp != 0 ) {
+	  mj_set_bpp(pdev, bpp);
+	  gdev_prn_put_params(pdev, plist);
 	  if ( bpp != old_bpp && pdev->is_open )
-	    { int ccode = gs_closedevice(pdev);
-	      if ( ccode < 0 ) return ccode;
-	    }
+	    return gs_closedevice(pdev);
+	  return 0;
 	}
-
-	return code;
+	else
+	  return gdev_prn_put_params(pdev, plist);
 }
 
 /* ------ Internal routines ------ */
@@ -1163,7 +1155,8 @@
 
   /* Send each scan line in turn */
   {
-    long int lend = pdev->height - (pdev->t_margin + pdev->b_margin) * y_dpi;
+    long int lend = pdev->height - 
+	(dev_t_margin_points(pdev) + dev_b_margin_points(pdev));
     int cErr, mErr, yErr, kErr;
     int this_pass, i;
     long int lnum;
@@ -1685,39 +1678,25 @@
 }
 
 private int
-put_prop_int(gs_prop_item *pi, int *property, int minval, int maxval, int code)
-{
-  if ( pi == 0 )
-    return (code);
-  
-  if ( pi->value.i < minval || pi->value.i > maxval )
-    { pi->status = pv_rangecheck;
-      return (gs_error_rangecheck);
-    }
-  else
-    { *property = pi->value.i;
-      return (code ? code : 1);
-    }
-}	
-
-private int
-put_prop_float(gs_prop_item *pi, float *property, float minval, float maxval, int code)
-{
-  if ( pi == 0 )
-    return (code);
-  
-  if ( pi->value.f < minval || pi->value.f > maxval )
-    { pi->status = pv_rangecheck;
-      return (gs_error_rangecheck);
-    }
-  else
-    { *property = pi->value.f;
-      return (code ? code : 1);
-    }
+mj_put_param_int(gs_param_list *plist, gs_param_name pname, int *pvalue,
+  int minval, int maxval, int ecode)
+{	int code, value;
+	switch ( code = param_read_int(plist, pname, &value) )
+	{
+	default:
+		return code;
+	case 1:
+		return ecode;
+	case 0:
+		if ( value < minval || value > maxval )
+		   param_signal_error(plist, pname, gs_error_rangecheck);
+		*pvalue = value;
+		return (ecode < 0 ? ecode : 1);
+	}
 }	
 
 private void
-set_bpp(gx_device *pdev, int bits_per_pixel)
+mj_set_bpp(gx_device *pdev, int bits_per_pixel)
 { gx_device_color_info *ci = &pdev->color_info;
   /* Only valid bits-per-pixel are 1, 3, 8, 16, 24, 32 */
   int bpp = bits_per_pixel < 3 ? 1 : bits_per_pixel < 8 ? 3 : 
@@ -1725,9 +1704,9 @@
   ci->num_components = ((bpp == 1) || (bpp == 8) ? 1 : 3);
   ci->depth = ((bpp > 1) && (bpp < 8) ? 8 : bpp);
   ci->max_gray = (bpp >= 8 ? 255 : 1);
-  ci->max_rgb = (bpp >= 8 ? 255 : bpp > 1 ? 1 : 0);
-  ci->dither_gray = (bpp >= 8 ? 5 : 2);
-  ci->dither_rgb = (bpp >= 8 ? 5 : bpp > 1 ? 2 : 0);
+  ci->max_color = (bpp >= 8 ? 255 : bpp > 1 ? 1 : 0);
+  ci->dither_grays = (bpp >= 8 ? 5 : 2);
+  ci->dither_colors = (bpp >= 8 ? 5 : bpp > 1 ? 2 : 0);
 }
 
 /* This returns either the number of pixels in a scan line, or the number
@@ -1736,7 +1715,7 @@
 gdev_prn_rasterwidth(const gx_device_printer *pdev, int pixelcount)
 {
   word raster_width =
-    pdev->width - pdev->x_pixels_per_inch * (pdev->l_margin + pdev->r_margin);
+    pdev->width - (pdev->HWMargins[0] + pdev->HWMargins[2]);
   return (pixelcount ?
           (uint)raster_width :
           (uint)((raster_width * pdev->color_info.depth + 7) >> 3));
