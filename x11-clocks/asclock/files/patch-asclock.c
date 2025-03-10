--- asclock.c.orig	1998-12-27 19:05:24 UTC
+++ asclock.c
@@ -1,4 +1,7 @@
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <unistd.h>
 #include <X11/Xlib.h>
 #include <X11/xpm.h>
 #include <X11/extensions/shape.h>
@@ -107,6 +110,7 @@ void usage()
   fprintf(stderr,"\n");
   exit(1);
 }
+int mytime(void);
 int main(int argc,char *argv[])
 {
   int i;
@@ -345,8 +349,8 @@ void GetXPM(void)
   static char **clock_xpm;
   XColor col;
   XWindowAttributes attributes;
-  char led1[23];
-  char led2[23];
+  char led1[64];
+  char led2[64];
   int ret;
 
   clock_xpm =ONLYSHAPE ? mask_xpm : clk_xpm;
@@ -360,18 +364,14 @@ void GetXPM(void)
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
 
 
   asclock.attributes.closeness = 40000; /* Allow for "similar" colors */
