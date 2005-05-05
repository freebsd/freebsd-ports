--- yuvdeinterlace.c.orig	Thu May  5 02:20:45 2005
+++ yuvdeinterlace.c	Thu May  5 02:20:45 2005
@@ -239,6 +239,7 @@
 
 		for (y=0; y<h; y+=2) 
 		{
+		register unsigned int x;
 
 				if (interlaced == Y4M_ILACE_BOTTOM_FIRST ) {
 					/* copy the luminance scan line from the odd frame */
@@ -256,7 +257,6 @@
 				}
 
 				/* average the chroma data */
-				unsigned int x;
 				for (x=0; x<(w>>1); x++) {
 					yuv_data[1][(y>>1)*(w>>1)+x]= (yuv_o1data[1][(y>>1)*(w>>1)+x]+yuv_o2data[1][(y>>1)*(w>>1)+x])/2 ;
 					yuv_data[2][(y>>1)*(w>>1)+x]= (yuv_o1data[2][(y>>1)*(w>>1)+x]+yuv_o2data[2][(y>>1)*(w>>1)+x])/2 ;
