--- src/gdevgdi.c.orig	Wed Jun 19 19:32:49 2002
+++ src/gdevgdi.c	Sun Nov 10 22:37:00 2002
@@ -86,9 +86,9 @@
 
 int GDI_BAND_WIDTH[] = {4768, 4928};
 
-private int gdi_print_page(P2(gx_device_printer *pdev, FILE *prn_stream));
-private int gdi_open(P1(gx_device *pdev));
-private int gdi_close(P1(gx_device *pdev));
+private int gdi_print_page(gx_device_printer *pdev, FILE *prn_stream);
+private int gdi_open(gx_device *pdev);
+private int gdi_close(gx_device *pdev);
 
 /* The device descriptors */
 private dev_proc_open_device(gdi_open);
