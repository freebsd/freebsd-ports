--- src/Glarea.h.orig	Tue Oct 15 01:13:37 2002
+++ src/Glarea.h	Tue Oct 15 01:15:44 2002
@@ -43,6 +43,8 @@
 #include "RenderEPS.h"	
 #include "IGBheader.h"
 
+using namespace std;
+
 typedef enum dispdim{DISP_XY, DISP_YZ, DISP_ZX, 
 								DISP_YX, DISP_ZY, DISP_XZ} DispDim; 
 typedef enum bbvalue{ BBXM, BBXP, BBYM, BBYP, BBZM, BBZP } BBvalue;
