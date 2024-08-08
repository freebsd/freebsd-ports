--- src/filter.c.orig	2024-03-13 01:23:02 UTC
+++ src/filter.c
@@ -32,6 +32,8 @@
 
 #include "epson-protocol.h"
 #include "epson-escpr-api.h"
+#include "epson-escpr-api-private.h"
+#include "epson-escpr-services.h"
 #include "epson-escpr-mem.h"
 
 #include "err.h"
@@ -41,6 +43,7 @@
 #include "libprtX.h"
 #include "optBase.h"
 #include "linux_cmn.h"
+#include "xfifo.h"
 
 #define WIDTH_BYTES(bits) (((bits) + 31) / 32 * 4)
 
@@ -225,7 +228,7 @@ main (int argc, char *argv[])
 	EPS_BANDBMP bandBmp;
 
 	/* Fifo for Backend */
-//	context = (void*)XFIFOOpen();
+	context = (void*)XFIFOOpen();
 
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////
 	memset (&jobAttr, 0, sizeof(jobAttr));
@@ -380,7 +383,7 @@ main (int argc, char *argv[])
 	}
 	
 	printJob.jobStatus = EPS_STATUS_ESTABLISHED;
-	int printHeight = 0;
+	EPS_UINT32 printHeight = 0;
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////	
 
 	print_area_x = printJob.printableAreaWidth;
@@ -409,7 +412,7 @@ main (int argc, char *argv[])
 	while ((read_page_no = read (STDIN_FILENO, &page_num, 1)) > 0)  // 最初に page番号を読み込み
 	{
 		long x_count, y_count;
-		int band_line_count;
+		EPS_UINT32 band_line_count;
 		y_count = 0;
 		band_line_count = 0;
 
@@ -497,7 +500,11 @@ main (int argc, char *argv[])
 					pagebuf+= bandBmp.widthBytes;
 					posbuf+=bandBmp.widthBytes;
 
+					if (band_line_count > printHeight) {
 					band_line_count -= printHeight;
+					} else {
+						band_line_count = 0;
+					}
 					bandBmp.bits += band_line_count;
 					
 				}
@@ -508,13 +515,17 @@ main (int argc, char *argv[])
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
@@ -658,7 +669,11 @@ main (int argc, char *argv[])
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
 				
@@ -680,7 +695,11 @@ main (int argc, char *argv[])
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
 
@@ -710,7 +729,7 @@ quit:;
 	mem_free(paper);
 	debug_msg("PRINT SUCCESS\n");
 
-//	XFIFOClose(&context);
+	XFIFOClose(&context);
 
 	return 0;
 }
@@ -871,7 +890,7 @@ static int  getMediaTypeID(char *rsc_name)
 
 EPS_INT32 print_spool_fnc(void* hParam, const EPS_UINT8* pBuf, EPS_UINT32 cbBuf) 
 {
-#if 1
+#if 0
 	long int i;
 	for (i = 0; i < cbBuf; i++)
 		putc(*(pBuf + i), outfp);
@@ -879,7 +898,7 @@ EPS_INT32 print_spool_fnc(void* hParam, const EPS_UINT
 
 //	fwrite (pBuf, cbBuf, 1, outfp);
 
-//	XFIFOWrite(context, pBuf, cbBuf);
+	XFIFOWrite(context, (char *)pBuf, cbBuf);
 
 	return 1;
 }
