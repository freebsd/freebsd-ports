--- bjc250/src/gdevbjc_.h.orig	Fri Nov  8 06:15:15 2002
+++ bjc250/src/gdevbjc_.h	Fri Nov  8 07:44:18 2002
@@ -183,48 +183,48 @@
 
 /* Put a BJL command to stream */
 
-void bjc_put_bjl_command(P2(FILE * file, int bjl_command));
+void bjc_put_bjl_command(FILE * file, int bjl_command);
 
-void bjc_put_LF(P1(FILE *file));
-void bjc_put_FF(P1(FILE *file));
-void bjc_put_CR(P1(FILE *file));
-void bjc_put_initialize(P1(FILE *file));
-void bjc_put_set_initial(P1(FILE *file));
-void bjc_put_set_compression(P2(FILE *file, char compression));
-void bjc_put_print_method_short(P2(FILE *file, char color));
-void bjc_put_print_method(P5(FILE *file, char color, char media, char quality, char density));
-void bjc_put_raster_resolution(P3(FILE *file, int x_resolution, int y_resolution));
-void bjc_put_raster_skip(P2(FILE *file, int skip));
-void bjc_put_page_margins(P5(FILE *file, int length, int lm, int rm, int top));
-void bjc_put_media_supply(P3(FILE *file, char supply, char type));
-void bjc_put_cmyk_image(P4(FILE *file, char component, const char *data, int count));
-void bjc_put_move_lines(P2(FILE *file, int lines));
-void bjc_put_move_lines_unit(P2(FILE *file, int unit));
-void bjc_put_extended_margins(P5(FILE *file, int length, int lm, int rm, int top));
-void bjc_put_image_format(P4(FILE *file, char depth, char format, char ink));
-void bjc_put_page_id(P2(FILE *file, int id));
-void bjc_put_continue_image(P3(FILE *file, const char *data, int count));
-void bjc_put_indexed_image(P4(FILE *file, int dot_rows, int dot_cols, int layers));
-
-bool bjc_invert_bytes(P4(byte *row, uint raster, bool inverse, byte lastmask));
-bool bjc_invert_cmyk_bytes(P8(byte *rowC,byte *rowM, byte *rowY, byte *rowK, uint raster,
-                              bool inverse, byte lastmask, skip_t *skip));
-uint bjc_compress(P3(const byte *row, uint raster, byte *compressed));
-
-int  FloydSteinbergInitG(P1(gx_device_printer * pdev));
-void FloydSteinbergDitheringG(P5(byte *row, byte *dithered, uint width, uint raster, bool limit_extr));
-void FloydSteinbergCloseG(P1(gx_device_printer *pdev));
-
-int  FloydSteinbergForwardCut(P5(int error, int *Errors, int i, byte *dithered, byte bitmask));
-int  FloydSteinbergBckwardCut(P5(int error, int *Errors, int i, byte *dithered, byte bitmask));
-int  FloydSteinbergInitC(P1(gx_device_printer * pdev));
-void FloydSteinbergDitheringC(P6(byte *row, byte *dithered, uint width, uint raster,
-                                 bool limit_extr, bool composeK));
-void FloydSteinbergCloseC(P1(gx_device_printer *pdev));
-
-void bjc_build_gamma_table(P2(float gamma, char color));
-void bjc_rgb_to_cmy (P6(byte r, byte g, byte b, int *c, int *m, int *y));
-void bjc_rgb_to_gray(P4(byte r, byte g, byte b, int *k));
+void bjc_put_LF(FILE *file);
+void bjc_put_FF(FILE *file);
+void bjc_put_CR(FILE *file);
+void bjc_put_initialize(FILE *file);
+void bjc_put_set_initial(FILE *file);
+void bjc_put_set_compression(FILE *file, char compression);
+void bjc_put_print_method_short(FILE *file, char color);
+void bjc_put_print_method(FILE *file, char color, char media, char quality, char density);
+void bjc_put_raster_resolution(FILE *file, int x_resolution, int y_resolution);
+void bjc_put_raster_skip(FILE *file, int skip);
+void bjc_put_page_margins(FILE *file, int length, int lm, int rm, int top);
+void bjc_put_media_supply(FILE *file, char supply, char type);
+void bjc_put_cmyk_image(FILE *file, char component, const char *data, int count);
+void bjc_put_move_lines(FILE *file, int lines);
+void bjc_put_move_lines_unit(FILE *file, int unit);
+void bjc_put_extended_margins(FILE *file, int length, int lm, int rm, int top);
+void bjc_put_image_format(FILE *file, char depth, char format, char ink);
+void bjc_put_page_id(FILE *file, int id);
+void bjc_put_continue_image(FILE *file, const char *data, int count);
+void bjc_put_indexed_image(FILE *file, int dot_rows, int dot_cols, int layers);
+
+bool bjc_invert_bytes(byte *row, uint raster, bool inverse, byte lastmask);
+bool bjc_invert_cmyk_bytes(byte *rowC,byte *rowM, byte *rowY, byte *rowK, uint raster,
+                              bool inverse, byte lastmask, skip_t *skip);
+uint bjc_compress(const byte *row, uint raster, byte *compressed);
+
+int  FloydSteinbergInitG(gx_device_printer * pdev);
+void FloydSteinbergDitheringG(byte *row, byte *dithered, uint width, uint raster, bool limit_extr);
+void FloydSteinbergCloseG(gx_device_printer *pdev);
+
+int  FloydSteinbergForwardCut(int error, int *Errors, int i, byte *dithered, byte bitmask);
+int  FloydSteinbergBckwardCut(int error, int *Errors, int i, byte *dithered, byte bitmask);
+int  FloydSteinbergInitC(gx_device_printer * pdev);
+void FloydSteinbergDitheringC(byte *row, byte *dithered, uint width, uint raster,
+                                 bool limit_extr, bool composeK);
+void FloydSteinbergCloseC(gx_device_printer *pdev);
+
+void bjc_build_gamma_table(float gamma, char color);
+void bjc_rgb_to_cmy (byte r, byte g, byte b, int *c, int *m, int *y);
+void bjc_rgb_to_gray(byte r, byte g, byte b, int *k);
 uint bjc_rand(void);
-void bjc_init_tresh(P1(int rnd));
+void bjc_init_tresh(int rnd);
 #endif				/* gdevbjc_INCLUDED */
