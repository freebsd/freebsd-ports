--- src/gdevdj9.c.orig	Fri Dec 17 19:31:42 2004
+++ src/gdevdj9.c	Fri Dec 17 19:44:07 2004
@@ -243,19 +243,19 @@
 };
 
 private int
-    rescale_byte_wise1x1(P4(int bytecount, const byte * inbytea,
-			    const byte * inbyteb, byte * outbyte));
+    rescale_byte_wise1x1(int bytecount, const byte * inbytea,
+			    const byte * inbyteb, byte * outbyte);
 private int
-    rescale_byte_wise2x1(P4(int bytecount, const byte * inbytea,
-			    const byte * inbyteb, byte * outbyte));
+    rescale_byte_wise2x1(int bytecount, const byte * inbytea,
+			    const byte * inbyteb, byte * outbyte);
 private int
-    rescale_byte_wise1x2(P4(int bytecount, const byte * inbytea,
-			    const byte * inbyteb, byte * outbyte));
+    rescale_byte_wise1x2(int bytecount, const byte * inbytea,
+			    const byte * inbyteb, byte * outbyte);
 private int
-    rescale_byte_wise2x2(P4(int bytecount, const byte * inbytea,
-			    const byte * inbyteb, byte * outbyte));
+    rescale_byte_wise2x2(int bytecount, const byte * inbytea,
+			    const byte * inbyteb, byte * outbyte);
 
-private int (* const rescale_color_plane[2][2]) (P4(int, const byte *, const byte *, byte *)) = {
+private int (* const rescale_color_plane[2][2]) (int, const byte *, const byte *, byte *) = {
     {
 	rescale_byte_wise1x1, rescale_byte_wise1x2
     },
@@ -264,7 +264,7 @@
     }
 };
 /*
-private int (* const rescale_color_plane[2][2]) (P4(int, const byte *, const byte *, byte *)) = {
+private int (* const rescale_color_plane[2][2]) (int, const byte *, const byte *, byte *) = {
     {
 	rescale_byte_wise1x1, rescale_byte_wise1x1
     },
@@ -273,8 +273,8 @@
     }
 };
 */
-private int cdj970_write_header(P2(gx_device *, FILE *));
-private int cdj970_write_trailer(P2(gx_device *, FILE *));
+private int cdj970_write_header(gx_device *, FILE *);
+private int cdj970_write_trailer(gx_device *, FILE *);
 
 /*
  * Drivers stuff.
@@ -422,16 +422,16 @@
 };
 
     /* function pointer typedefs for device driver struct */
-typedef void (*StartRasterMode) (P3(gx_device_printer * pdev, int paper_size,
-				    FILE * prn_stream));
-typedef void (*PrintNonBlankLines) (P6(gx_device_printer * pdev,
+typedef void (*StartRasterMode) (gx_device_printer * pdev, int paper_size,
+				    FILE * prn_stream);
+typedef void (*PrintNonBlankLines) (gx_device_printer * pdev,
 				       struct ptr_arrays *data_ptrs,
 				       struct misc_struct *misc_vars,
 				       struct error_val_field *error_values,
 				       const Gamma *gamma,
-				       FILE * prn_stream));
+				       FILE * prn_stream);
 
-typedef void (*TerminatePage) (P2(gx_device_printer * pdev, FILE * prn_stream));
+typedef void (*TerminatePage) (gx_device_printer * pdev, FILE * prn_stream);
 
 typedef struct gx_device_cdj970_s {
     gx_device_common;
@@ -529,18 +529,18 @@
 }
 
 private void
-     cdj970_start_raster_mode(P3(gx_device_printer * pdev,
-				 int papersize, FILE * prn_stream));
+     cdj970_start_raster_mode(gx_device_printer * pdev,
+				 int papersize, FILE * prn_stream);
 
 private void
-     cdj970_print_non_blank_lines(P6(gx_device_printer * pdev,
+     cdj970_print_non_blank_lines(gx_device_printer * pdev,
 				     struct ptr_arrays *data_ptrs,
 				     struct misc_struct *misc_vars,
 				     struct error_val_field *error_values,
 				     const Gamma *gamma,
-				     FILE * prn_stream));
+				     FILE * prn_stream);
 private void
-     cdj970_terminate_page(P2(gx_device_printer * pdev, FILE * prn_stream));
+     cdj970_terminate_page(gx_device_printer * pdev, FILE * prn_stream);
 
 
 private const gx_device_procs cdj970_procs =
@@ -555,12 +555,12 @@
 				cdj970_terminate_page);
 
 /* Forward references */
-private int cdj_put_param_int(P6(gs_param_list *, gs_param_name,
-				 int *, int, int, int));
-private int cdj_put_param_float(P6(gs_param_list *, gs_param_name, float
-				   *, float, float, int));
-private int cdj_put_param_bpp(P5(gx_device *, gs_param_list *, int, int, int));
-private int cdj_set_bpp(P3(gx_device *, int, int));
+private int cdj_put_param_int(gs_param_list *, gs_param_name,
+				 int *, int, int, int);
+private int cdj_put_param_float(gs_param_list *, gs_param_name, float
+				   *, float, float, int);
+private int cdj_put_param_bpp(gx_device *, gs_param_list *, int, int, int);
+private int cdj_set_bpp(gx_device *, int, int);
 
 static int PageCtr = 0;
 
@@ -692,70 +692,70 @@
 
 /* internal functions */
 private void
-     FSDlinebw(P7(int scan, int plane_size,
+     FSDlinebw(int scan, int plane_size,
 		  struct error_val_field *error_values,
 		  byte * kP,
-		  int n, int *ep, byte * dp));
+		  int n, int *ep, byte * dp);
 		  
 private void
-     FSDlinec2(P9(int scan, int plane_size,
+     FSDlinec2(int scan, int plane_size,
 		  struct error_val_field *error_values,
 		  byte * cPa, byte * mPa, byte * yPa, int n,
-		  byte * dp, int *ep));
+		  byte * dp, int *ep);
 		  
 private void
-     FSDlinec3(P12(int scan, int plane_size,
+     FSDlinec3(int scan, int plane_size,
 		   struct error_val_field *error_values,
 		   byte * cPa, byte * mPa, byte * yPa,
 		   byte * cPb, byte * mPb, byte * yPb,
-		   int n, byte * dp, int *ep));
+		   int n, byte * dp, int *ep);
 		   
 private void
-     FSDlinec4(P12(int scan, int plane_size,
+     FSDlinec4(int scan, int plane_size,
 		   struct error_val_field *error_values,
 		   byte * cPa, byte * mPa, byte * yPa,
 		   byte * cPb, byte * mPb, byte * yPb,
-		   int n, byte * dp, int *ep));
+		   int n, byte * dp, int *ep);
 
 private void
      init_error_buffer(struct misc_struct *misc_vars,
 		       struct ptr_arrays *data_ptrs);
 		       
 private void
-     do_floyd_steinberg(P8(int scan, int cscan, int plane_size,
+     do_floyd_steinberg(int scan, int cscan, int plane_size,
 			   int plane_size_c, int n,
 			   struct ptr_arrays *data_ptrs,
 			   gx_device_printer * pdev,
-			   struct error_val_field *error_values));
+			   struct error_val_field *error_values);
 
 			   	   
 private int
-    do_gcr(P7(int bytecount, byte * inbyte, const byte * kvalues,
+    do_gcr(int bytecount, byte * inbyte, const byte * kvalues,
 	      const byte * cvalues, const byte * mvalues,
-	      const byte * yvalues, const int *kcorrect));
+	      const byte * yvalues, const int *kcorrect);
 	      
 private void
-     send_scan_lines(P6(gx_device_printer * pdev,
+     send_scan_lines(gx_device_printer * pdev,
 			struct ptr_arrays *data_ptrs,
 			struct misc_struct *misc_vars,
 			struct error_val_field *error_values,
 			const Gamma *gamma,
-			FILE * prn_stream));
+			FILE * prn_stream);
 			
 private void
-     do_gamma(P3(float mastergamma, float gammaval, byte * values));
+     do_gamma(float mastergamma, float gammaval, byte * values);
      
 private void
-     do_black_correction(P2(float kvalue, int *kcorrect));
+     do_black_correction(float kvalue, int *kcorrect);
 
 private void
-     init_data_structure(P3(gx_device_printer * pdev,
+     init_data_structure(gx_device_printer * pdev,
 			    struct ptr_arrays *data_ptrs,
-			    struct misc_struct *misc_vars));
+			    struct misc_struct *misc_vars);
 			    
 private void
-     calculate_memory_size(P2(gx_device_printer * pdev,
-			      struct misc_struct *misc_vars));
+     calculate_memory_size(gx_device_printer * pdev,
+			      struct misc_struct *misc_vars);
 
 
 /* assign_dpi:  
@@ -863,7 +863,7 @@
 		 2bpp feature of the hp970 someday, it is sized like storage.
 		 storagee contains the errors from b/w fs-ditherng */
 
-	data_ptrs.storage = (ulong *) gs_malloc(misc_vars.storage_size_words, W,
+	data_ptrs.storage = (ulong *) gs_malloc(pdev->memory, misc_vars.storage_size_words, W,
 					    "cdj970_print_page");
 
 	/* if we can't allocate working area */
@@ -884,7 +884,7 @@
 	(*cdj970->terminate_page) (pdev, prn_stream);
 
 	/* Free Memory */
-	gs_free((char *)data_ptrs.storage, misc_vars.storage_size_words, W,
+	gs_free(pdev->memory, (char *)data_ptrs.storage, misc_vars.storage_size_words, W,
 	    "hp970_print_page");
 
 	PageCtr ++;
@@ -2292,12 +2292,13 @@
 /* gdev_cmyk_map_cmyk_color: 
 ----------------------------------------------------------------------------------*/
 private gx_color_index gdev_cmyk_map_cmyk_color(gx_device 			*pdev,
-																								gx_color_value 	cyan, 
-																								gx_color_value 	magenta,
-																								gx_color_value 	yellow,
-																								gx_color_value 	black)
+																								const gx_color_value 	cv[])
 {
 	gx_color_index color;
+	gx_color_value cyan = cv[0];
+	gx_color_value magenta = cv[1];
+	gx_color_value yellow = cv[2];
+	gx_color_value black = cv[3];
 
 	switch (pdev->color_info.depth) {
 		case 1:
@@ -2331,10 +2332,11 @@
 /* gdev_cmyk_map_rgb_color: Mapping of RGB colors to gray values. 
 ----------------------------------------------------------------------------------*/
 private gx_color_index gdev_cmyk_map_rgb_color(	gx_device 			*pdev, 
-																								gx_color_value 	r, 
-																								gx_color_value 	g, 
-																								gx_color_value 	b)
+																								const gx_color_value 	cv[])
 {
+	gx_color_value r = cv[0];
+	gx_color_value g = cv[1];
+	gx_color_value b = cv[2];
 	if (gx_color_value_to_byte(r & g & b) == 0xff) {
 		return (gx_color_index) 0;	/* White */
 	} else {
@@ -2427,10 +2429,11 @@
 /* gdev_pcl_map_rgb_color: 
 ----------------------------------------------------------------------------------*/
 private gx_color_index gdev_pcl_map_rgb_color(	gx_device 			*pdev, 
-																								gx_color_value 	r,
-																								gx_color_value 	g, 
-																								gx_color_value 	b)
+																								const gx_color_value 	cv[])
 {
+	gx_color_value r = cv[0];
+	gx_color_value g = cv[1];
+	gx_color_value b = cv[2];
 	if (gx_color_value_to_byte(r & g & b) == 0xff)
 		return (gx_color_index) 0;	/* white */
 	else {
