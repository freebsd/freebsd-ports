--- gp_cppsupport/gprinter.cpp.orig	2010-04-30 03:44:31.000000000 +0400
+++ gp_cppsupport/gprinter.cpp	2019-12-04 18:01:52.055955000 +0300
@@ -22,7 +22,6 @@
 #include <gutenprint/gutenprint.h>
 
 #include <glib.h>
-#include <glib/gstrfuncs.h>
 #include <glib/gprintf.h>
 
 #include "../imagesource/imagesource.h"
@@ -418,59 +417,72 @@ void GPrinter::Print(ImageSource *src,int xpos,int ypo
 
 void GPrinter::GetImageableArea()
 {
-//	pagewidth=pageheight=0;
-//	stp_get_media_size(stpvars, &pagewidth, &pageheight);
+	stp_dimension_t double_pagewidth, double_pageheight;
+	stp_get_media_size(stpvars, &double_pagewidth, &double_pageheight);
 
-//	Debug[TRACE] << "Media size returned: " << pagewidth << " by " << pageheight << endl;
+	// *** HACK ***
+	// Gutenprint uses doubles... Either rewrite all funclions to use doubles or deal with it just here.
 
-	const char *papersize=stp_get_string_parameter(stpvars,"PageSize");
-	bool gotpapersize=false;
-	if(papersize)
-	{
-		const stp_papersize_t *paper=stp_get_papersize_by_name(papersize);
-		if(paper)
+	pagewidth=(int)double_pagewidth;
+	pageheight=(int)double_pageheight;
+
+	Debug[TRACE] << "Media size returned: " << pagewidth << " by " << pageheight << endl;
+
+	// From gutenprint TFM:
+	// If the media size is invalid, width and height will be set to -1.
+
+	if (pagewidth != -1 && pageheight != -1) {
+
+		// From gutenprint TFM:
+		// Values of 0 for width or height indicate that the dimension
+ 		// is variable, so that custom page sizes or roll paper can be used.
+ 		// In this case, the size limit should be used to determine maximum and
+ 		// minimum values permitted.
+
+		if(!pagewidth)
 		{
-			gotpapersize=true;
-			if(paper->width)
-			{
-				pagewidth=minwidth=maxwidth=paper->width;
-				stp_set_page_width(stpvars,pagewidth);
-				Debug[TRACE] << "Width: " << pagewidth << endl;
-			}
-			else
-			{
-				int mw,mh,nw,nh;
-				pagewidth=stp_get_page_width(stpvars);
-				stp_get_size_limit(stpvars,&mw,&mh,&nw,&nh);
-				minwidth=nw;
-				maxwidth=mw;
-				Debug[TRACE] << "Custom width..." << endl;
-			}
-			if(paper->height)
-			{
-				pageheight=minheight=maxheight=paper->height;
-				stp_set_page_height(stpvars,pageheight);
-				Debug[TRACE] << "Height: " << pageheight << endl;
-			}
-			else
-			{
-				int mw,mh,nw,nh;
-				pageheight=stp_get_page_height(stpvars);
-				stp_get_size_limit(stpvars,&mw,&mh,&nw,&nh);
-				minheight=nh;
-				maxheight=mh;
-				Debug[TRACE] << "Custom height..." << endl;
-			}
+			stp_dimension_t dmw,dmh,dnw,dnh;
+			double_pagewidth=stp_get_page_width(stpvars);
+			stp_get_size_limit(stpvars,&dmw,&dmh,&dnw,&dnh);
+
+			// *** HACK ***
+			// Gutenprint uses doubles... Either rewrite all funclions to use doubles or deal with it just here.
+
+			minwidth=(int)dnw;
+			maxwidth=(int)dmw;
+			Debug[TRACE] << "Custom width..." << endl;
 		}
+
+		if(!pageheight)
+		{
+			stp_dimension_t dmw,dmh,dnw,dnh;
+			double_pageheight=stp_get_page_height(stpvars);
+			stp_get_size_limit(stpvars,&dmw,&dmh,&dnw,&dnh);
+
+			// *** HACK ***
+			// Gutenprint uses doubles... Either rewrite all funclions to use doubles or deal with it just here.
+
+			minheight=(int)dnh;
+			maxheight=(int)dmh;
+			Debug[TRACE] << "Custom height..." << endl;
+		}
 	}
-	if(!gotpapersize)
-	{
-		pagewidth=pageheight=0;
-		stp_get_media_size(stpvars, &pagewidth, &pageheight);
-	}
+	else {
+		// How should we treat an invalid media size?
+	}	
 
+	stp_dimension_t double_l,double_r,double_t,double_b;
+	stp_get_imageable_area(stpvars, &double_l, &double_r, &double_b, &double_t);
+
 	int l,r,t,b;
-	stp_get_imageable_area(stpvars, &l, &r, &b, &t);
+
+	// *** HACK ***
+	// Gutenprint uses doubles... Either rewrite all funclions to use doubles or deal with it just here.
+
+	l=(int)double_l;
+	r=(int)double_r;
+	t=(int)double_t;
+	b=(int)double_b;
 
 	Debug[TRACE] << "Imageable area from GP: L: " << l << ", R: " << r << ", T: " << t << ", B: " << b << endl;
 
