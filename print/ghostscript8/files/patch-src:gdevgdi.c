--- src/gdevgdi.c.orig	Wed Jun 19 19:32:49 2002
+++ src/gdevgdi.c	Fri Dec 31 17:41:18 2004
@@ -60,8 +60,8 @@
 #define GDI_REPEAT_LENGTH 2
 #define GDI_BAND_HEIGHT   128
 #define GDI_MAX_BAND      66
-//#define GDI_BAND_WIDTH    4928
-//#define GDI_BAND_WIDTH_BYTES (((GDI_BAND_WIDTH + 31)/32)*4)
+/*#define GDI_BAND_WIDTH    4928*/
+/*#define GDI_BAND_WIDTH_BYTES (((GDI_BAND_WIDTH + 31)/32)*4)*/
 
 #define GDI_PRE_COMP      2
 #define GDI_REAL_COMP     0
@@ -74,8 +74,8 @@
 
 #define GDI_MARGINS_A4	        0.167, 0.167, 0.167, 0.167
 #define GDI_MARGINS_LETTER	0.167, 0.167, 0.167, 0.167
-//#define GDI_MARGINS_A4	0.0, 0.0, 0.0, 0.0
-//#define GDI_MARGINS_LETTER	0.0, 0.0, 0.0, 0.0
+/*#define GDI_MARGINS_A4	0.0, 0.0, 0.0, 0.0*/
+/*#define GDI_MARGINS_LETTER	0.0, 0.0, 0.0, 0.0*/
 
 /* The number of blank lines that make it worthwhile to reposition */
 /* the cursor. */
@@ -86,9 +86,15 @@
 
 int GDI_BAND_WIDTH[] = {4768, 4928};
 
+#if GS_VERSION_MAJOR >= 8
+private int gdi_print_page(gx_device_printer *pdev, FILE *prn_stream);
+private int gdi_open(gx_device *pdev);
+private int gdi_close(gx_device *pdev);
+#else
 private int gdi_print_page(P2(gx_device_printer *pdev, FILE *prn_stream));
 private int gdi_open(P1(gx_device *pdev));
 private int gdi_close(P1(gx_device *pdev));
+#endif
 
 /* The device descriptors */
 private dev_proc_open_device(gdi_open);
@@ -107,6 +113,14 @@
 	1,                      /* color bit */ 
         gdi_print_page);
 
+gx_device_printer far_data gs_samsunggdi_device =
+  prn_device(prn_gdi_procs, "samsunggdi",
+	DEFAULT_WIDTH_10THS, DEFAULT_HEIGHT_10THS, /* paper size (unit : 10/72 inch size) */
+	X_DPI2, Y_DPI2,
+	0.20, 0.25, 0.25, 0.25,		/* margins filled in by gdi_open */
+	1,                      /* color bit */ 
+        gdi_print_page);
+
 private FILE *WritePJLHeaderData(gx_device_printer *pdev, FILE *fp);
 private FILE *WriteBandHeader(FILE *fp, unsigned int usBandNo, 
                      unsigned char ubCompMode, unsigned int usBandWidth, 
@@ -193,9 +207,9 @@
 	}
 
         ul_band_size = band_width_bytes * band_height;
-        ibp = (byte *)gs_malloc(ul_band_size, 1, "gdi_print_page");
-        obp = (byte *)gs_malloc(ul_band_size*13/10, 1, "gdi_print_page");
-        tmp = (byte *)gs_malloc(raster, 1, "gdi_print_page");
+        ibp = (byte *)gs_malloc(pdev->memory, ul_band_size, 1, "gdi_print_page");
+        obp = (byte *)gs_malloc(pdev->memory, ul_band_size*13/10, 1, "gdi_print_page");
+        tmp = (byte *)gs_malloc(pdev->memory, raster, 1, "gdi_print_page");
 
         if (!ibp) return_error(gs_error_VMerror);
         if (!obp) return_error(gs_error_VMerror);
@@ -220,7 +234,7 @@
             memset(obp, 0x00, ul_band_size*13/10);
             for (j=0; j<band_height; j++) {
                 memset(tmp, 0x00, raster);
-                //code = gdev_prn_copy_scan_lines(pdev, i*band_height+j, 
+                /*code = gdev_prn_copy_scan_lines(pdev, i*band_height+j, */
 		if (y == num_rows) break;
                 code = gdev_prn_copy_scan_lines(pdev, y++, 
                                  (byte*)tmp, raster);
@@ -232,15 +246,71 @@
 
             /* Write Band Data 
 	       Because of Scanline compression, extract Scanline compression mode */
-            //ul_tiff_size = FrameTiffComp(obp, ibp, band_height, band_width_bytes, GDI_PRE_COMP);
-            //ul_scan_size = (unsigned long)bmp2run(obp, ibp, band_height, band_width_bytes, GDI_PRE_COMP);
-	    //ul_min_size =  (ul_scan_size > ul_tiff_size) ? ul_tiff_size : ul_scan_size;
+            /*ul_tiff_size = FrameTiffComp(obp, ibp, band_height, band_width_bytes, GDI_PRE_COMP);*/
+            /*ul_scan_size = (unsigned long)bmp2run(obp, ibp, band_height, band_width_bytes, GDI_PRE_COMP);*/
+	    /*ul_min_size =  (ul_scan_size > ul_tiff_size) ? ul_tiff_size : ul_scan_size;*/
 	    ul_min_size = ul_tiff_size;
 	    compression_type = GDI_COMP_MODITIFF;
-	    //compression_type =  (ul_scan_size > ul_tiff_size) ? GDI_COMP_MODITIFF : GDI_COMP_SCANLINE;
+	    /*compression_type =  (ul_scan_size > ul_tiff_size) ? GDI_COMP_MODITIFF : GDI_COMP_SCANLINE;*/
             switch (compression_type) {
 	    case GDI_COMP_MODITIFF:
+#define FUDGE_BIG_BANDS
+#ifndef FUDGE_BIG_BANDS
                 ul_comp_size = FrameTiffComp(obp, ibp, band_height, band_width_bytes, GDI_REAL_COMP);
+#else
+	      {
+		/* Very ugly.  The printer will hose if the compressed
+                   band size is over 65536, so we "fudge" the data in
+                   this case repeatedly until we get what we want. 
+
+		   The fudge algorithm is simple, this is kinda-sorta
+		   RLE, so we just round groups of bits in groups of
+		   2, then 3, then 4, etc until the thing works.  */
+#define MAXBAND 0xffff
+#define ASSERT(x)
+		int fudge=0;
+		byte *use_band=ibp;
+		do {
+		  ul_comp_size = FrameTiffComp(obp, use_band, 
+					       band_height, band_width_bytes, 
+					       GDI_REAL_COMP);
+		  if (ul_comp_size > MAXBAND-8) {
+		    int f, g, h;
+		    if (!fudge) {
+		      ASSERT(use_band == ibp);
+		      use_band = (byte*)gs_malloc(pdev->memory, ul_band_size, 1, "gdi_print_page/fudge");
+		      fudge=1;
+		    }
+		    memcpy(use_band, ibp, ul_band_size);
+		    fudge++;
+		    ASSERT(fudge>=2);
+		    {
+#define FUDGE2(x) ( (((((x)>>6)&0x3)?3:0)<<6)	\
+		    | (((((x)>>4)&0x3)?3:0)<<4)	\
+		    | (((((x)>>2)&0x3)?3:0)<<2)	\
+		    | (((((x)>>0)&0x3)?3:0)) )
+#define FUDGE4(x) ( (((((x)>>4)&0xf)?0xf:0)<<4)	\
+		    | (((((x)>>0)&0xf)?0xf:0)) )
+#define FUDGE8(x) ( (((((x)>>0)&0xff)?0xf:0)) )
+#define FUDGE(fudge, x) ( (fudge == 2 ? FUDGE2(x) 	\
+			   : fudge == 3 ? FUDGE4(x)	\
+			   : fudge == 4 ? FUDGE8(x)	\
+			   : 0 ) )
+
+		      for(f=0;f<ul_band_size; f++) {
+			use_band[f] = FUDGE(fudge, ibp[f]);
+		      }
+		    }
+		  }
+		} while (ul_comp_size > MAXBAND-8);
+	      oh_well:
+		if (fudge > 1) {
+		  ASSERT(use_band != ibp);
+		  gs_free(pdev->memory, use_band, ul_band_size, 1, "gdi_print_page/fudge");
+		  /*fprintf(stderr, "smartgdi: band %d fudge factor is %d\n", i, fudge);*/
+		}
+	      }
+#endif
 		break;
 	    case GDI_COMP_SCANLINE:
                 ul_comp_size = bmp2run(obp, ibp, band_height, band_width_bytes, GDI_REAL_COMP);
@@ -253,15 +323,15 @@
 
             prn_stream = WriteBandHeader(prn_stream, i, compression_type, (band_width_bytes * 8),
                                          band_height, ul_comp_size); 
-            //fprintf(prn_stream, "[%d] band, size : %d\n", i, ul_tiff_size);
+            /*fprintf(prn_stream, "[%d] band, size : %d\n", i, ul_tiff_size);*/
             fwrite(obp, ul_comp_size, 1, prn_stream);
         }
     
         /* Trailer Output */
         WriteTrailerData(prn_stream);
-        gs_free(ibp, ul_band_size, 1, "gdi_line_buffer");
-        gs_free(obp, ul_band_size*13/10, 1, "gdi_line_buffer");
-        gs_free(tmp, raster, 1, "gdi_line_buffer");
+        gs_free(pdev->memory, ibp, ul_band_size, 1, "gdi_line_buffer");
+        gs_free(pdev->memory, obp, ul_band_size*13/10, 1, "gdi_line_buffer");
+        gs_free(pdev->memory, tmp, raster, 1, "gdi_line_buffer");
         return code;
 }
 
@@ -271,50 +341,50 @@
   unsigned char buffer[300];
   int dots_per_inch = (int)pdev->y_pixels_per_inch;
 
-  strcpy(buffer, "\x1b%-12345X");
+  strcpy(buffer, "\033%-12345X");
   
-  // Paper Type
-  strcat(buffer, "@PJL SET PAPERTYPE = NORMAL ON\x0d\x0a");
-  //Density
-  strcat(buffer, "@PJL SET DENSITY = 1\x0d\x0a");
-  // Toner Save
-  strcat(buffer, "@PJL SET TONERSAVE = OFF\x0d\x0a");
-  // Enter Language SMART
-  strcat(buffer, "@PJL ENTER LANGUAGE = SMART\x0d\x0a");
-  // JobStart
-  strcat(buffer, "$PJL JOB START\x0d\x0a");
+  /* Paper Type*/
+  strcat(buffer, "@PJL SET PAPERTYPE = NORMAL ON\015\012");
+  /*Density*/
+  strcat(buffer, "@PJL SET DENSITY = 1\015\012");
+  /* Toner Save*/
+  strcat(buffer, "@PJL SET TONERSAVE = OFF\015\012");
+  /* Enter Language SMART*/
+  strcat(buffer, "@PJL ENTER LANGUAGE = SMART\015\012");
+  /* JobStart*/
+  strcat(buffer, "$PJL JOB START\015\012");
 
-  // Resolution
+  /* Resolution*/
   if (dots_per_inch == 600)
-      strcat(buffer, "$PJL RESOLUTION = 600\x0d\x0a");
+      strcat(buffer, "$PJL RESOLUTION = 600\015\012");
   else
-      strcat(buffer, "$PJL RESOLUTION = 300\x0d\x0a");
+      strcat(buffer, "$PJL RESOLUTION = 300\015\012");
 
-  // Copies
-  strcat(buffer, "$PJL COPIES = 1\x0d\x0a");
-  // Paper Size
+  /* Copies*/
+  strcat(buffer, "$PJL COPIES = 1\015\012");
+  /* Paper Size*/
   switch (gdev_pcl_paper_size((gx_device*)pdev)) 
   {
 	case PAPER_SIZE_A4:
-  			strcat(buffer, "$PJL PAGE A4 AUTO\x0d\x0a");
+  			strcat(buffer, "$PJL PAGE A4 AUTO\015\012");
 			break;
 	case PAPER_SIZE_LETTER:
-  			strcat(buffer, "$PJL PAGE LETTER AUTO\x0d\x0a");
+  			strcat(buffer, "$PJL PAGE LETTER AUTO\015\012");
 			break;
 	case PAPER_SIZE_LEGAL:
-  			strcat(buffer, "$PJL PAGE LEGAL AUTO\x0d\x0a");
+  			strcat(buffer, "$PJL PAGE LEGAL AUTO\015\012");
 			break;
 	default:
-  			strcat(buffer, "$PJL PAGE LETTER AUTO\x0d\x0a");
+  			strcat(buffer, "$PJL PAGE LETTER AUTO\015\012");
 			break;
   }
-  // bitmap start
-  strcat(buffer, "$PJL BITMAP START\x0d\x0a");
-  // write buffer to file.
+  /* bitmap start*/
+  strcat(buffer, "$PJL BITMAP START\015\012");
+  /* write buffer to file.*/
   ulSize = strlen(buffer);
   fwrite(buffer, 1, ulSize, fp );
   return(fp);
-} // WritePJLHeaderData()     
+} /* WritePJLHeaderData()     */
 
 
 FILE *WriteBandHeader
@@ -335,33 +405,33 @@
 
   ulBandSize += 8;
 
-  // bandsize
+  /* bandsize*/
   buf[i++] = (unsigned char)((ulBandSize >> 24) & 0xff);
   buf[i++] = (unsigned char)((ulBandSize >> 16) & 0xff);
   buf[i++] = (unsigned char)((ulBandSize >> 8) & 0xff);
   buf[i++] = (unsigned char)(ulBandSize & 0xff);
   
-  // id                            
+  /* id        */                    
   buf[i++] = (unsigned char)((usBandNo >> 8) & 0xff);
   buf[i++] = (unsigned char)(usBandNo & 0xff);
 
-  // compress mode         
+  /* compress mode         */
   buf[i++] = (unsigned char)(ubCompMode & 0xff);
 
-  // ubLeft                  
+  /* ubLeft                  */
   buf[i++] = (unsigned char)(ubLeft & 0xff);
 
-  // height
+  /* height*/
   buf[i++] = (unsigned char)((usBandHeight >> 8) & 0xff);
   buf[i++] = (unsigned char)(usBandHeight & 0xff);
 
-  // width                     
+  /* width   */                  
   buf[i++] = (unsigned char)((usBandWidth >> 8) & 0xff);
   buf[i++] = (unsigned char)(usBandWidth & 0xff);
 
   fwrite(buf, 1, i, fp);
   return(fp);
-} // end of WriteBandHeader()
+} /* end of WriteBandHeader()*/
 
 FILE *WriteTrailerData(FILE *fp)
 {
@@ -369,18 +439,18 @@
   unsigned long buffer[200];
 
   memset((char*)buffer, 0x00, 200);
-  strcpy((char*)buffer, "$PJL PRINT 4\x0d\x0a");
-  strcat((char*)buffer, "$PJL EOJ\x0d\x0a");
-  strcat((char*)buffer, "$PJL SYNC\x0d\x0a");
-  strcat((char*)buffer, "$PJL RELEASE 0 2047\x0d\x0a");
-  strcat((char*)buffer, "$PJL GARBAGE\x0d\x0a");
-  strcat((char*)buffer, "\x1b%-12345X\x0d\x0a");
+  strcpy((char*)buffer, "$PJL PRINT 4\015\012");
+  strcat((char*)buffer, "$PJL EOJ\015\012");
+  strcat((char*)buffer, "$PJL SYNC\015\012");
+  strcat((char*)buffer, "$PJL RELEASE 0 2047\015\012");
+  strcat((char*)buffer, "$PJL GARBAGE\015\012");
+  strcat((char*)buffer, "\033%-12345X\015\012");
 
   ulSize = strlen((char*)buffer);
   fwrite(buffer, 1, ulSize, fp);
 
   return(fp);
-} // WriteTrailerData()
+} /* WriteTrailerData()*/
 
 unsigned long FrameTiffComp(unsigned char *pubDest, 
                             unsigned char *pubSrc, 
@@ -399,7 +469,7 @@
 
   for (i = 0; i < usTotalLines; i++)
   {
-    if (!(ubMode & 0x02)) //
+    if (!(ubMode & 0x02))
     {
       usLineSize = FrameTiff_Comp(SrcPtr, TgtPtr, usBytesPerLine);
     }
@@ -416,7 +486,7 @@
     ulret += usLineSize;
   }
 
-  if (!(ubMode & 0x02)) //
+  if (!(ubMode & 0x02))
   {
     switch (ulret%4)
     {
@@ -448,7 +518,7 @@
     }
   }
   return(ulret);
-}  // FrameTiffComp()
+}  /* FrameTiffComp()*/
 
 unsigned int FrameTiff_Comp(unsigned char *lpSrcBuf, unsigned char *lpTgtBuf, unsigned int nSrcBytes)
 {
@@ -528,13 +598,13 @@
           usEndCnt = 16384;
         }
         usEndCnt = usCount - 2;
-        // usEndCnt = usCount - 2; original
-        // 19990824 by LSM : for end file while (usEndCnt--)
+        /* usEndCnt = usCount - 2; original*/
+        /* 19990824 by LSM : for end file while (usEndCnt--)*/
         while (usEndCnt--)
         {
           /* read next data */
           ubFirst = ubSecond;
-          ubSecond = *pubSrc++; // read 3rd Data
+          ubSecond = *pubSrc++; /* read 3rd Data*/
           if (ubFirst == ubSecond)
           {
             if (usEndCnt <= 1)
@@ -544,7 +614,7 @@
             }
             else
             {
-              ubSecond = *pubSrc++; // read 4th Data
+              ubSecond = *pubSrc++; /* read 4th Data*/
               usEndCnt--;
               if (ubFirst == ubSecond)
               {
@@ -660,14 +730,14 @@
         {
           usEndCnt = 16384;
         }
-        // usEndCnt = usCount - 2;
+        /* usEndCnt = usCount - 2;*/
         usEndCnt = usCount - 2;
-        // 19990824 by LSM : for Last file while (usEndCnt--)
+        /* 19990824 by LSM : for Last file while (usEndCnt--)*/
         while (usEndCnt--)
         {
           /* read next data */
           ubFirst = ubSecond;
-          ubSecond = *pubSrc++; // read 3rd Data
+          ubSecond = *pubSrc++; /* read 3rd Data*/
           if (ubFirst == ubSecond)
           {
             if (usEndCnt <= 1)
@@ -677,8 +747,8 @@
             }
             else
             {
-              ubSecond = *pubSrc++; // read 4th Data
-              usEndCnt--; // 19990824 by LSM
+              ubSecond = *pubSrc++; /* read 4th Data*/
+              usEndCnt--; /* 19990824 by LSM*/
               if (ubFirst == ubSecond)
               {
                 ubMisCnt = 3;
@@ -691,7 +761,7 @@
       /* save data */
       usControl = (unsigned int) (pubSrc - pubOrg);
       usControl -= ubMisCnt;
-      // 19990824 by LSM : for fixing GPF on Photoshop
+      /* 19990824 by LSM : for fixing GPF on Photoshop*/
       if (usControl > usCount)
       {
         usControl = usCount;
@@ -728,77 +798,77 @@
 }   sc_tbl;
 
 static sc_tbl  gdi_ScanTbl[256] = {
-{ 8, 0, 0 }, { 7, 1, 1 }, { 6, 1, 0 }, { 6, 2, 1 },   // 0x00
+{ 8, 0, 0 }, { 7, 1, 1 }, { 6, 1, 0 }, { 6, 2, 1 },   /* 0x00*/
 { 5, 1, 0 }, { 0, 0, 1 }, { 5, 2, 0 }, { 5, 3, 1 }, 
 { 4, 1, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 4, 2, 0 }, { 0, 0, 1 }, { 4, 3, 0 }, { 4, 4, 1 }, 
-{ 3, 1, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   // 0x10
+{ 3, 1, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   /* 0x10*/
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 3, 2, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 3, 3, 0 }, { 0, 0, 1 }, { 3, 4, 0 }, { 3, 5, 1 }, 
-{ 2, 1, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   // 0x20
+{ 2, 1, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   /* 0x20*/
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
-{ 2, 2, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   // 0x30
+{ 2, 2, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   /* 0x30*/
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 2, 3, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 2, 4, 0 }, { 0, 0, 1 }, { 2, 5, 0 }, { 2, 6, 1 }, 
-{ 1, 1, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   // 0x40
+{ 1, 1, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   /* 0x40*/
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
-{ 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   // 0x50
+{ 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   /* 0x50*/
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
-{ 1, 2, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   // 0x60
+{ 1, 2, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   /* 0x60*/
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
-{ 1, 3, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   // 0x70
+{ 1, 3, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   /* 0x70*/
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 1, 4, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 1, 5, 0 }, { 0, 0, 1 }, { 1, 6, 0 }, { 1, 7, 1 }, 
-{ 0, 1, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   // 0x80
+{ 0, 1, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   /* 0x80*/
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
-{ 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   // 0x90
+{ 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   /* 0x90*/
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
-{ 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   // 0xa0
+{ 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   /* 0xa0*/
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
-{ 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   // 0xb0
+{ 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   /* 0xb0*/
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
-{ 0, 2, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   // 0xc0
+{ 0, 2, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   /* 0xc0*/
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
-{ 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   // 0xd0
+{ 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   /* 0xd0*/
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
-{ 0, 3, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   // 0xe0
+{ 0, 3, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   /* 0xe0*/
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
-{ 0, 4, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   // 0xf0
+{ 0, 4, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   /* 0xf0*/
 { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 0, 5, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, 
 { 0, 6, 0 }, { 0, 0, 1 }, { 0, 7, 0 }, { 0, 8, 1 }, 
 };
 
 static sc_tbl  gdi_ScanTbl4[16] = {
-{ 4, 0, 0 }, { 3, 1, 1 }, { 2, 1, 0 }, { 2, 2, 1 },   // 0x00
-{ 1, 1, 0 }, { 0, 0, 1 }, { 1, 2, 0 }, { 1, 3, 1 },   // 0x04
-{ 0, 1, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   // 0x08
-{ 0, 2, 0 }, { 0, 0, 1 }, { 0, 3, 0 }, { 0, 4, 1 }    // 0x0c
+{ 4, 0, 0 }, { 3, 1, 1 }, { 2, 1, 0 }, { 2, 2, 1 },   /* 0x00*/
+{ 1, 1, 0 }, { 0, 0, 1 }, { 1, 2, 0 }, { 1, 3, 1 },   /* 0x04*/
+{ 0, 1, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 },   /* 0x08*/
+{ 0, 2, 0 }, { 0, 0, 1 }, { 0, 3, 0 }, { 0, 4, 1 }    /* 0x0c*/
 };
 
 long SaveScanData( unsigned char *, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short );
@@ -816,32 +886,32 @@
   lWarp = (long)(usWarp << 3);
   lDis  = ((long)usDy * lWarp) + (long)sDx;
 
-  // 1st, 2nd, 3rd & 4th byte
-  ultmp_dat = 0xc0000000;
+  /* 1st, 2nd, 3rd & 4th byte*/
+  ultmp_dat = 0xc0000000ul;
   if (lDis < 0)
   {
-    ultmp_dat |= 0x20000000;
+    ultmp_dat |= 0x20000000ul;
   }
-  ultmp_dat |= (lDis & 0x1fffffff);
-  *out_buf++ = (unsigned char)((ultmp_dat & 0xff000000) >> 24);
-  *out_buf++ = (unsigned char)((ultmp_dat & 0xff0000) >> 16);
-  *out_buf++ = (unsigned char)((ultmp_dat & 0xff00) >> 8);
-  *out_buf++ = (unsigned char)(ultmp_dat & 0xff);
+  ultmp_dat |= (lDis & 0x1ffffffful);
+  *out_buf++ = (unsigned char)((ultmp_dat & 0xff000000ul) >> 24);
+  *out_buf++ = (unsigned char)((ultmp_dat & 0xff0000ul) >> 16);
+  *out_buf++ = (unsigned char)((ultmp_dat & 0xff00ul) >> 8);
+  *out_buf++ = (unsigned char)(ultmp_dat & 0xfful);
 
-  // 5th & 6th byte
+  /* 5th & 6th byte*/
   ustmp_dat = 0xc000;
   ustmp_dat |= (usRl & 0x3fff);
   *out_buf++ = (unsigned char)((ustmp_dat & 0xff00) >> 8);
   *out_buf++ = (unsigned char)(ustmp_dat & 0xff);
 
   return(6);
-} // Save6Bytes()
+} /* Save6Bytes()*/
 
 long  Save4Bytes(unsigned char *out_buf, unsigned short usDy, unsigned short usRl, short sDx)
 {
   unsigned short  ustmp_dat;
 
-  // 1st & 2nd byte
+  /* 1st & 2nd byte*/
   ustmp_dat = 0x8000;
   if (sDx < 0)
   {
@@ -851,7 +921,7 @@
   *out_buf++ = (unsigned char)((ustmp_dat & 0xff00) >> 8);
   *out_buf++ = (unsigned char)(ustmp_dat & 0xff);
 
-  // 3rd & 4th byte
+  /* 3rd & 4th byte*/
   ustmp_dat = 0x8000;
   ustmp_dat |= ((usDy & 0x03) << 12);
   ustmp_dat |= (usRl & 0xfff);
@@ -859,13 +929,13 @@
   *out_buf++ = (unsigned char)(ustmp_dat & 0xff);
 
   return(4);
-}   // end of Save4Bytes()
+}   /* end of Save4Bytes()*/
 
 long  Save2Bytes(unsigned char *out_buf, unsigned short usDy, unsigned short usRl, short sDx)
 {
   unsigned char ubtmp_dat;
 
-  // 1st byte
+  /* 1st byte*/
   ubtmp_dat = 0x00;
   if (usDy == 1)
   {
@@ -874,7 +944,7 @@
   ubtmp_dat |= (usRl & 0x3f);
   *out_buf++ = ubtmp_dat;
 
-  // 2nd byte
+  /* 2nd byte*/
   if (sDx < 0)
   {
     ubtmp_dat = 0x80;
@@ -886,7 +956,7 @@
   ubtmp_dat |= ((unsigned char)sDx & 0x7f);
   *out_buf++ = ubtmp_dat;
   return(2);
-}   // end of Save2Bytes()
+}   /* end of Save2Bytes()*/
 
 long SaveScanData (unsigned char *out_buf, 
                    unsigned short us1Cnt, 
@@ -900,26 +970,26 @@
 
   sDisX = (int)usPosX01 - (int)usPosX10;
 
-  // 48 bit
+  /* 48 bit*/
   if ( (usDy > 3) || (us1Cnt > 4095) ) 
   {
     Save6Bytes(out_buf, usDy, us1Cnt, sDisX, usWarp);
     lRet = 6;
   }
-  // 32 bit
+  /* 32 bit*/
   else if ( (usDy > 1) || (us1Cnt > 63) || (sDisX > 127) || (sDisX < -128) ) 
   {
     Save4Bytes(out_buf, usDy, us1Cnt, sDisX);
     lRet = 4;
   }
-  // 16 bit
+  /* 16 bit*/
   else 
   {
     Save2Bytes(out_buf, usDy, us1Cnt, sDisX);
     lRet = 2;
   }
   return(lRet);
-} // end of SaveScanData()
+} /* end of SaveScanData()*/
 
 
 long UpdateScanSize (unsigned char *out_buf, 
@@ -934,23 +1004,23 @@
 
   sDisX = usPosX01 - usPosX10;
 
-  // 48 bit
+  /* 48 bit*/
   if ( (usDy > 3) || (us1Cnt > 4095) ) 
   {
     lRet = 6;
   }
-  // 32 bit
+  /* 32 bit*/
   else if ( (usDy > 1) || (us1Cnt > 63) || (sDisX > 127) || (sDisX < -128) )
   {
     lRet = 4;
   }
-  // 16 bit
+  /* 16 bit*/
   else
   {
     lRet = 2;
   }
   return(lRet);
-} // end of UpdateScanSize() by bglee 19981224
+} /* end of UpdateScanSize() by bglee 19981224*/
 
 long GetSimpleScan(unsigned char *out_buf,
                    unsigned char ubSizeMode, 
@@ -983,10 +1053,10 @@
   }
 
   
-  // 1 X 1 X
+  /* 1 X 1 X*/
   if (ubPreBit) 
   {
-    // 1 0 1 X
+    /* 1 0 1 X*/
     if (ubDx) 
     {
       lScanSize += (*UpdateScanLine[ubSizeMode])(out_buf, *us1Count, *usDy, *usPosX10, *usPosX01, usWidth);
@@ -994,23 +1064,23 @@
       *usPosX01 = usBytePos + ubDx;
       *us1Count = ubRl;
       *usDy = 0;
-      // 1 0 1 0
+      /* 1 0 1 0*/
       if (!ubLastBit) 
       {
-        // 19990330 by bglee
+        /* 19990330 by bglee*/
         out_buf = out_buf + lScanSize;
         
         lScanSize += (*UpdateScanLine[ubSizeMode])(out_buf, *us1Count, *usDy, *usPosX10, *usPosX01, usWidth);
         *usPosX10 = *usPosX01 ;
         *us1Count = 0;
       }
-      // 1 0 1 1
+      /* 1 0 1 1*/
     }
-    // 1 1 1 X
+    /* 1 1 1 X*/
     else 
     {
       *us1Count += ubRl;
-      // 1 1 1 0
+      /* 1 1 1 0*/
       if (!ubLastBit) 
       {
         lScanSize += (*UpdateScanLine[ubSizeMode])(out_buf, *us1Count, *usDy, *usPosX10, *usPosX01, usWidth);
@@ -1018,16 +1088,16 @@
         *us1Count = 0;
         *usDy = 0;
       }
-      // 1 1 1 1
+      /* 1 1 1 1*/
     }
   }
-  // 0 X 1 X
+  /* 0 X 1 X*/
   else 
   {
-    // 0 X 1 X
+    /* 0 X 1 X*/
     *usPosX01 = usBytePos + ubDx;
     *us1Count += ubRl;
-    // 0 X 1 0
+    /* 0 X 1 0*/
     if (!ubLastBit) 
     {
       lScanSize += (*UpdateScanLine[ubSizeMode])(out_buf, *us1Count, *usDy, *usPosX10, *usPosX01, usWidth);
@@ -1035,11 +1105,11 @@
       *us1Count = 0;
       *usDy = 0;
     }
-    // 0 X 1 1
+    /* 0 X 1 1*/
   }
 
   return(lScanSize);
-} // end of GetSimpleScan() 
+} /* end of GetSimpleScan() */
 
 
 long scan_map (unsigned char *in_buf, 
@@ -1049,7 +1119,7 @@
                unsigned char ubMode) 
 {
   unsigned int  i, j, k;
-  unsigned char ubPreBit, ubCrtByte;//, ubLastBit;
+  unsigned char ubPreBit, ubCrtByte;/*, ubLastBit;*/
   long  lScanSize, lTmp;
   long lCrtSize;
   unsigned short  us1Count;
@@ -1078,7 +1148,7 @@
       switch (ubCrtByte) 
       {
         case 0x00:
-          // 1 0
+          /* 1 0 */
           if (ubPreBit) 
           {
             lTmp = (*UpdateScanLine[ubSizeMode])(out_buf, us1Count, usDy, usPosX10, usPosX01, usWidth);
@@ -1088,16 +1158,16 @@
             us1Count = 0;
             usDy = 0;
           }
-          // 0 0
+          /* 0 0*/
           break;
 
         case 0xff:
-          // 1 1
+          /* 1 1*/
           if (ubPreBit)
           {
             us1Count += 8;
           }
-          // 0 1
+          /* 0 1*/
           else 
           {
             us1Count = 8;
@@ -1106,7 +1176,7 @@
           break;
 
         default:
-          // X X 1 X
+          /* X X 1 X*/
           if (gdi_ScanTbl[ubCrtByte].ubRl) 
           {
             usBytePos = (j << 3);
@@ -1114,7 +1184,7 @@
             out_buf = out_buf + lTmp;
             lScanSize += lTmp;
           }
-          // complex pattern
+          /* complex pattern*/
           else 
           {
             for (k = 0; k < 2; k++) 
@@ -1124,7 +1194,7 @@
               switch (ubTemp) 
               {
                 case 0x00:
-                  // 1 0
+                  /* 1 0*/
                   if (ubPreBit) 
                   {
                     lTmp = (*UpdateScanLine[ubSizeMode])(out_buf, us1Count, usDy, usPosX10, usPosX01, usWidth);
@@ -1134,16 +1204,16 @@
                     us1Count = 0;
                     usDy = 0;
                   }
-                  // 0 0
+                  /* 0 0*/
                   break;
 
                 case 0x0f:
-                  // 1 1
+                  /* 1 1*/
                   if (ubPreBit)
                   {
                     us1Count += 4;
                   }
-                  // 0 1
+                  /* 0 1*/
                   else 
                   {
                     us1Count = 4;
@@ -1152,7 +1222,7 @@
                   break;
 
                 case 0x05:
-                  // 1 0101
+                  /* 1 0101*/
                   if (ubPreBit) 
                   {
                     lTmp = (*UpdateScanLine[ubSizeMode])(out_buf, us1Count, usDy, usPosX10, usPosX01, usWidth);
@@ -1162,13 +1232,13 @@
                     usPosX10 = usBytePos - us1Count;
                     usDy = 0;
                   }
-                  // 0 0101
+                  /* 0 0101*/
                   usPosX01 = usBytePos + 1;
                   lTmp = (*UpdateScanLine[ubSizeMode])(out_buf, 1, usDy, usPosX10, usPosX01, usWidth);
                   out_buf = out_buf + lTmp;
                   lScanSize += lTmp;
 
-                  // next
+                  /* next*/
                   usPosX10 = 0;
                   usPosX01 = 2;
                   usDy = 0;
@@ -1176,12 +1246,12 @@
                             break;
 
                 case 0x09:
-                  // 1 1001
+                  /* 1 1001*/
                   if (ubPreBit)
                   {
                     us1Count++;
                   }
-                  // 0 1001
+                  /* 0 1001*/
                   else 
                   {
                     usPosX01 = usBytePos;
@@ -1191,7 +1261,7 @@
                   out_buf = out_buf + lTmp;
                   lScanSize += lTmp;
 
-                  // next
+                  /* next*/
                   if (ubPreBit)
                   {       
                     usPosX10 = usBytePos - us1Count + 1;
@@ -1207,12 +1277,12 @@
                   break;
 
                 case 0x0a:
-                  // 1 1010
+                  /* 1 1010*/
                   if (ubPreBit)
                   {
                     us1Count++;
                   }
-                  // 0 1010
+                  /* 0 1010*/
                   else 
                   {
                     us1Count = 1;
@@ -1222,25 +1292,25 @@
                   out_buf = out_buf + lTmp;
                   lScanSize += lTmp;
 
-                  // next
+                  /* next*/
                   usPosX10 = usBytePos - us1Count + 1;
                   usPosX01 = usBytePos + 2;
                   lTmp = (*UpdateScanLine[ubSizeMode])(out_buf, 1, 0, usPosX10, usPosX01, usWidth);
                   out_buf = out_buf + lTmp;
                   lScanSize += lTmp;
-                  // next
+                  /* next*/
                   usPosX10 = usBytePos + 2;
                   usDy = 0;
                   us1Count = 0;
                   break;
 
                 case 0x0b:
-                  // 1 1011
+                  /* 1 1011*/
                   if (ubPreBit)
                   {
                     us1Count++;
                   }
-                  // 0 1011
+                  /* 0 1011*/
                   else 
                   {
                     us1Count = 1;
@@ -1250,7 +1320,7 @@
                   out_buf = out_buf + lTmp;
                   lScanSize += lTmp;
 
-                  // next
+                  /* next*/
                   if (ubPreBit)
                   {       
                     usPosX10 = usBytePos - us1Count + 1;
@@ -1267,12 +1337,12 @@
                   break;
 
                 case 0x0d:
-                  // 1 1101
+                  /* 1 1101*/
                   if (ubPreBit)
                   {
                     us1Count += 2;
                   }
-                  // 0 1101
+                  /* 0 1101*/
                   else 
                   {
                     us1Count = 2;
@@ -1282,7 +1352,7 @@
                   out_buf = out_buf + lTmp;
                   lScanSize += lTmp;
 
-                  // next
+                  /* next*/
                   if (ubPreBit)
                   {
                     usPosX10 = usBytePos - us1Count + 2;
@@ -1298,17 +1368,17 @@
                   break;
 
                 default:
-                  // X X 1 X
+                  /* X X 1 X*/
                   lTmp = GetSimpleScan(out_buf, ubSizeMode, &us1Count, &usDy, &usPosX10, &usPosX01, usBytePos, ubTemp, 4, ubPreBit, usWidth);
                   out_buf = out_buf + lTmp;
                   lScanSize += lTmp;
                   break;
-              } // end of switch()
+              } /* end of switch()*/
               ubPreBit = ubTemp & 0x01;
-            } // end of k-loop
+            } /* end of k-loop*/
           }
           break;
-      } // end of switch()
+      } /* end of switch()*/
 
       ubPreBit = ubCrtByte & 0x01;
     } /*for  usWidth */
@@ -1326,7 +1396,7 @@
     }
     usDy++;
 
-    // check size over
+    /* check size over*/
     if ( (i % 5) == 4 ) 
     {
       lCrtSize = (long)((long)usWidth * (long)(i + 1));
@@ -1342,7 +1412,7 @@
     lScanSize = -1;
   }
   return(lScanSize);
-} // end of scan_map() 
+} /* end of scan_map() */
 
 /*****************************************************************
  *  H : bmp2run
@@ -1362,7 +1432,7 @@
   unsigned char *tmp_buf1, *tmp_buf2;
   long  scan_size;
 
-  //return(-1); // 19990323 by bglee - request from SM Lee
+  /*return(-1);*/ /* 19990323 by bglee - request from SM Lee*/
   
   tmp_buf1 = in_buf;
   tmp_buf2 = out_buf;
@@ -1372,7 +1442,7 @@
     return(-1);
   }
 
-  if ( !(ubMode & 0x02) )  // real compression //---
+  if ( !(ubMode & 0x02) )  /* real compression */
   {
     out_buf = tmp_buf2 + scan_size;
     *out_buf++ = 0x00;
@@ -1385,7 +1455,7 @@
       scan_size += 2;
     }
   }
-  else    // pre-compression
+  else    /* pre-compression*/
   {
     scan_size += 2;
     if (scan_size % 4) 
