--- lips/gdevl4r.c.orig	Thu Nov  2 12:09:18 2000
+++ lips/gdevl4r.c	Sun Nov 10 21:12:14 2002
@@ -178,8 +178,8 @@
 private int lips4c_output_page(gx_device_printer * pdev, FILE * prn_stream);
 private int lips_delta_encode(byte * inBuff, byte * prevBuff, byte * outBuff, byte * diffBuff, int Length);
 private int lips_byte_cat(byte * TotalBuff, byte * Buff, int TotalLen, int Len);
-private int lips_print_page_copies(P4(gx_device_printer * pdev, FILE * prn_stream, lips_printer_type ptype, int numcopies));
-private int lips_print_page_copies(P4(gx_device_printer * pdev, FILE * prn_stream, lips_printer_type ptype, int numcopies));
+private int lips_print_page_copies(gx_device_printer * pdev, FILE * prn_stream, lips_printer_type ptype, int numcopies);
+private int lips_print_page_copies(gx_device_printer * pdev, FILE * prn_stream, lips_printer_type ptype, int numcopies);
 private int lips4type_print_page_copies(gx_device_printer * pdev, FILE * prn_stream, int num_copies, int ptype);
 
 private int
