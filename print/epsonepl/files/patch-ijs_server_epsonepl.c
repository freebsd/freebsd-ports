--- ijs_server_epsonepl.c.orig	Wed Jan 22 23:10:24 2003
+++ ijs_server_epsonepl.c	Fri Feb 14 16:47:16 2003
@@ -34,7 +34,6 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <malloc.h>
 #include "ijs.h"
 #include "ijs_server.h"
 
@@ -541,7 +540,9 @@
 
   /* Check options */
 
+#ifdef EPL_DEBUG
   fprintf(stderr, "settings:\n");
+#endif
 
   if (epl_job_info->outfile == NULL)
     {
@@ -596,7 +597,10 @@
       fprintf(stderr, "Unknown Printer %s, aborting!\n", s);
       return 1;
     }
+
+#ifdef EPL_DEBUG
   fprintf(stderr, "  Using protocol for %s\n",printername[epl_job_info->model]);
+#endif
 
 
   /* PaperSize */
@@ -622,7 +626,9 @@
           fprintf(stderr, "Unparsable PaperSize %s, aborting!", s);
           return 1;
 	}
+#ifdef EPL_DEBUG
       fprintf(stderr, "  Papersize is %s inches\n", s);
+#endif
     }
 
 
@@ -659,7 +665,10 @@
       fprintf(stderr, "Unknown EplDpi value %s, aborting!\n", s);
       return 1;
     }
+
+#ifdef EPL_DEBUG
   fprintf(stderr, "  Printing at DPI %s\n", s);
+#endif
 
   /* EplRitech */
   s = find_param(pl, "EplRitech");
@@ -681,7 +690,10 @@
       fprintf(stderr, "Unknown EplRitech value %s, aborting!\n", s);
       return 1;
     }
+
+#ifdef EPD_DEBUG
   fprintf(stderr, "  Ritech is %s\n", s);
+#endif
 
   /* EplDensity */
   s = find_param(pl, "EplDensity");
@@ -715,7 +727,10 @@
       fprintf(stderr, "Unknown EplDensity value %s, aborting!\n", s);
       return 1;
     }
+
+#ifdef EPL_DEBUG
   fprintf(stderr, "  Density is %s\n", s);
+#endif
 
   /* EplTonerSave */
   s = find_param(pl, "EplTonerSave");
@@ -737,7 +752,10 @@
       fprintf(stderr, "Unknown EplTonerSave value %s, aborting!\n", s);
       return 1;
     }
+
+#ifdef EPL_DEBUG
   fprintf(stderr, "  TonerSave is %s\n", s);
+#endif
 
   /* Number of channels */
   if (ph.bps != 1)
@@ -758,11 +776,13 @@
   /* BitMap Size */
   epl_job_info->pixel_h = ph.width;
   epl_job_info->pixel_v = ph.height;
+#ifdef DEBUG
   fprintf(stderr, "  Bitmap size %ix%i (%gx%g in)\n",
           epl_job_info->pixel_h,
 	  epl_job_info->pixel_v,
 	  (double)epl_job_info->pixel_h / epl_job_info->dpi_h,
 	  (double)epl_job_info->pixel_v / epl_job_info->dpi_v);
+#endif
 
   /* Dpi of the bitmap */
   if (ph.xres != (double)epl_job_info->dpi_h
@@ -811,7 +831,7 @@
   fprintf(stderr, "Try to allocate %i byte of memory for job info\n",sizeof(EPL_job_info));
 #endif
   
-  epl_job_info = (EPL_job_info *)malloc(sizeof(EPL_job_info));
+  epl_job_info = (EPL_job_info *)calloc(1, sizeof(EPL_job_info));
   
   if (epl_job_info == NULL) {
 #ifdef EPL_DEBUG
@@ -833,7 +853,9 @@
       int i_stripe;
       typ_stream *stream;
       
+#ifdef EPL_DEBUG
       fprintf (stderr, "getting page header\n");
+#endif
       
       status = ijs_server_get_page_header (ctx, &ph);
       
@@ -852,9 +874,10 @@
 	  break;
 	}
       
+#ifdef EPL_DEBUG
       fprintf (stderr, "got page header, width %d x height %d\n",
 	       ph.width, ph.height);
-      
+
       /* Before starting, dump IJS parameters */
 
       for (curs = pl; curs != NULL; curs = curs->next)
@@ -863,6 +886,7 @@
 	  fwrite (curs->value, 1, curs->value_size, stderr);
 	  fputs ("\n", stderr);
 	}
+#endif
 
       /* Convert parameters to internal format */
 
