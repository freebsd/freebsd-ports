--- src/filter.c.orig	2019-07-31 06:49:48 UTC
+++ src/filter.c
@@ -32,7 +32,10 @@
 
 #include "epson-protocol.h"
 #include "epson-escpr-api.h"
+#include "epson-escpr-api-private.h"
+#include "epson-escpr-services.h"
 #include "epson-escpr-mem.h"
+#include "epson-escpage.h"
 
 #include "err.h"
 #include "mem.h"
@@ -41,6 +44,7 @@
 #include "libprtX.h"
 #include "optBase.h"
 #include "linux_cmn.h"
+#include "xfifo.h"
 
 #define WIDTH_BYTES(bits) (((bits) + 31) / 32 * 4)
 
@@ -380,7 +384,7 @@ main (int argc, char *argv[])
 	}
 	
 	printJob.jobStatus = EPS_STATUS_ESTABLISHED;
-	int printHeight = 0;
+	EPS_UINT32 printHeight = 0;
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////	
 
 	print_area_x = printJob.printableAreaWidth;
@@ -409,7 +413,7 @@ main (int argc, char *argv[])
 	while ((read_page_no = read (STDIN_FILENO, &page_num, 1)) > 0)  // 最初に page番号を読み込み
 	{
 		long x_count, y_count;
-		int band_line_count;
+		EPS_UINT32 band_line_count;
 		y_count = 0;
 		band_line_count = 0;
 
@@ -497,7 +501,11 @@ main (int argc, char *argv[])
 					pagebuf+= bandBmp.widthBytes;
 					posbuf+=bandBmp.widthBytes;
 
+					if (band_line_count > printHeight) {
 					band_line_count -= printHeight;
+					} else {
+						band_line_count = 0;
+					}
 					bandBmp.bits += band_line_count;
 					
 				}
@@ -508,13 +516,17 @@ main (int argc, char *argv[])
 				memcpy(pagebuf, bandBmp.bits, bandBmp.widthBytes);
 				pagebuf+= bandBmp.widthBytes;
 				posbuf+= bandBmp.widthBytes;
+				if (band_line_count > printHeight) {
 				band_line_count -= printHeight;
+				} else {
+					band_line_count = 0;
+				}
 				bandBmp.bits += band_line_count;
 			}
 		
 			int revert = 0;
 			int pos = posbuf - bandBmp.widthBytes ;
-			char *rever_buf = malloc(bandBmp.widthBytes + 1000);
+			EPS_UINT8 *rever_buf = (EPS_UINT8 *)malloc(bandBmp.widthBytes + 1000);
 			for (revert = print_area_y; revert > 0; revert--)
 			{
 				if (3 != byte_par_pixel)
@@ -658,7 +670,11 @@ main (int argc, char *argv[])
 #endif
 					debug_msg("printHeight = %d\n", printHeight);
 					debug_msg("widthByte = %d\n", bandBmp.widthBytes);
+					if (band_line_count > printHeight) {
 					band_line_count -= printHeight;
+					} else {
+						band_line_count = 0;
+					}
 					bandBmp.bits += band_line_count;
 				}
 				
@@ -680,7 +696,11 @@ main (int argc, char *argv[])
 				fprintf(fp, "\n");
 				fclose(fp);
 #endif
+				if (band_line_count > printHeight) {
 				band_line_count -= printHeight;
+				} else {
+					band_line_count = 0;
+				}
 				bandBmp.bits += band_line_count;
 			}
 
@@ -879,7 +899,7 @@ EPS_INT32 print_spool_fnc(void* hParam, const EPS_UINT
 
 //	fwrite (pBuf, cbBuf, 1, outfp);
 
-	XFIFOWrite(context, pBuf, cbBuf);
+	XFIFOWrite(context, (char *)pBuf, cbBuf);
 
 	return 1;
 }
