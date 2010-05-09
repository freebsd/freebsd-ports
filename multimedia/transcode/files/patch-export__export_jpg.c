http://bugs.gentoo.org/show_bug.cgi?id=294488

Patch by: Salah Coronya

Fix segmentation fault with jpeg-7 and above where dinfo.do_fancy_upsampling isn't set by default to FALSE anymore.

--- export/export_jpg.c
+++ export/export_jpg.c
@@ -91,6 +91,7 @@
 
   jpeg_set_quality(&encinfo, quality, TRUE);
   encinfo.raw_data_in = TRUE;
+  encinfo.do_fancy_downsampling = FALSE;
   encinfo.in_color_space = JCS_YCbCr;
 
   encinfo.comp_info[0].h_samp_factor = 2;
