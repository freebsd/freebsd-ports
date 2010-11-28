--- src/main.c	2004-12-11 19:07:21.000000000 +0000
+++ src/main.c	2007-01-31 12:20:47.000000000 +0000
@@ -66,10 +66,8 @@
 int main(int argc, char **argv)
 {
    int i, a, aa, b, bb;
-   char* real_off_xpm[(style == 2 ? sizeof(backlight2_off_xpm) :
-                       sizeof(backlight_off_xpm))];
-   char* real_on_xpm[(style == 2 ? sizeof(backlight2_on_xpm) :
-                       sizeof(backlight_on_xpm))];
+   char** real_off_xpm;
+   char** real_on_xpm;
    XEvent event;
    XpmColorSymbol colors[2] = { {"Back0", NULL, 0}, {"Back1", NULL, 0} };
    int ncolor = 0;
@@ -79,20 +77,12 @@
    
    /* setup pixmap to use - this is ugly but it works */
    
-   a = sizeof(backlight2_off_xpm);
-   aa = sizeof(backlight2_on_xpm);
-   b = sizeof(backlight_off_xpm);
-   bb = sizeof(backlight_on_xpm);
    if(style == 2){
-      for(i=0; i<a; i++)
-         real_off_xpm[i] = backlight2_off_xpm[i];
-      for(i=0; i<aa; i++)
-         real_on_xpm[i] = backlight2_on_xpm[i];
+       real_off_xpm = backlight2_off_xpm;
+       real_on_xpm = backlight2_on_xpm;
    } else {
-      for(i=0; i<b; i++)
-         real_off_xpm[i] = backlight_off_xpm[i];
-      for(i=0; i<bb; i++)
-         real_on_xpm[i] = backlight_on_xpm[i];
+       real_off_xpm = backlight_off_xpm;
+       real_on_xpm = backlight_on_xpm;
    }
 
    /* Initialize Application */
