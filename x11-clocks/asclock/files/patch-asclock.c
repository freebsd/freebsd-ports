--- asclock.c.orig	1996-08-25 22:35:49 UTC
+++ asclock.c
@@ -1,4 +1,7 @@
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <unistd.h>
 #include <X11/Xlib.h>
 #include <X11/xpm.h>
 #include <X11/extensions/shape.h>
@@ -245,6 +248,7 @@ int main(int argc,char *argv[])
 	      InsertTime();
 	    }
 	  if (ITBLINKS)
+           {
 	    if (actualtime % 2)
 	      /* Sekunden Doppelpunkt ein */
 	      XCopyArea(dpy, led.pixmap, visible.pixmap, NormalGC,
@@ -253,6 +257,7 @@ int main(int argc,char *argv[])
 	      /* Sekunden Doppelpunkt aus */
 	      XCopyArea(dpy, asclock.pixmap, visible.pixmap, NormalGC,
 			27,6,3,11,posx[2], posy[0]);
+	   }
 	  
 	  RedrawWindow(&visible);
 
@@ -302,8 +307,8 @@ void GetXPM(void)
   static char **clock_xpm;
   XColor col;
   XWindowAttributes attributes;
-  char led1[22];
-  char led2[22];
+  char led1[64];
+  char led2[64];
   int ret;
 
   clock_xpm =ONLYSHAPE ? mask_xpm : clk_xpm;
@@ -317,51 +322,49 @@ void GetXPM(void)
       nocolor("parse",LedColor);
     }
 
-  sprintf(&led1[0], ".      c #%4X%4X%4X", col.red, col.green, col.blue);
-  for(ret=10;ret<22;ret++)
-    if(led1[ret]==' ') led1[ret]='0';
-  led_xpm[2] = &led1[0];
+  sprintf(led1, ".      c #%04X%04X%04X", col.red, col.green, col.blue);
+  led_xpm[2] = led1;
 
   col.red   = (col.red  /10) *3;
   col.green = (col.green/10) *3;
   col.blue  = (col.blue /10) *3;
-  sprintf(&led2[0], "X      c #%4X%4X%4X", col.red, col.green, col.blue);
-  for(ret=10;ret<22;ret++)
-    if(led2[ret]==' ') led2[ret]='0';
-  led_xpm[3] = &led2[0];
+  sprintf(led2, "X      c #%04X%04X%04X", col.red, col.green, col.blue);
+  led_xpm[3] = led2;
 
   asclock.attributes.valuemask |= (XpmReturnPixels | XpmReturnExtensions);
   ret = XpmCreatePixmapFromData(dpy, Root, clock_xpm, &asclock.pixmap, 
 				&asclock.mask, &asclock.attributes);
   if(ret != XpmSuccess)
-    {fprintf(stderr, ERR_colorcells);exit(1);}
+    {fprintf(stderr, "1: %s\n", XpmGetErrorString(ret));exit(1);}
   visible.attributes.valuemask |= (XpmReturnPixels | XpmReturnExtensions);
   ret = XpmCreatePixmapFromData(dpy, Root, clk_xpm, &visible.pixmap, 
 				&visible.mask, &visible.attributes);
+  if(ret != XpmSuccess)
+    {fprintf(stderr, "2: %s\n", XpmGetErrorString(ret));exit(1);}
 
   led.attributes.valuemask |= (XpmReturnPixels | XpmReturnExtensions);
   ret = XpmCreatePixmapFromData(dpy, Root, led_xpm, &led.pixmap, 
 				&led.mask, &led.attributes);
   if(ret != XpmSuccess)
-    {fprintf(stderr, ERR_colorcells);exit(1);}
+    {fprintf(stderr, "3: %s\n", XpmGetErrorString(ret));exit(1);}
 
   month.attributes.valuemask |= (XpmReturnPixels | XpmReturnExtensions);
   ret = XpmCreatePixmapFromData(dpy, Root, month_xpm, &month.pixmap, 
 				&month.mask, &month.attributes);
   if(ret != XpmSuccess)
-    {fprintf(stderr, ERR_colorcells);exit(1);}
+    {fprintf(stderr, "4: %s\n", XpmGetErrorString(ret));exit(1);}
 
   date.attributes.valuemask |= (XpmReturnPixels | XpmReturnExtensions);
   ret = XpmCreatePixmapFromData(dpy, Root, date_xpm, &date.pixmap, 
 				&date.mask, &date.attributes);
   if(ret != XpmSuccess)
-    {fprintf(stderr, ERR_colorcells);exit(1);}
+    {fprintf(stderr, "5: %s\n", XpmGetErrorString(ret));exit(1);}
 
   weekday.attributes.valuemask |= (XpmReturnPixels | XpmReturnExtensions);
   ret = XpmCreatePixmapFromData(dpy, Root, weekday_xpm, &weekday.pixmap, 
 				&weekday.mask, &weekday.attributes);
   if(ret != XpmSuccess)
-    {fprintf(stderr, ERR_colorcells);exit(1);}
+    {fprintf(stderr, "6: %s\n", XpmGetErrorString(ret));exit(1);}
 }
 /****************************************************************************/
 /* Removes expose events for a specific window from the queue */
