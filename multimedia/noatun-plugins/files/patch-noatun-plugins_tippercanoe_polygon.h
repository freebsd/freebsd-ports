===================================================================
RCS file: /usr/repos/kde/kdeaddons/noatun-plugins/tippercanoe/polygon.h,v
retrieving revision 1.3
retrieving revision 1.3.8.1
diff -u -p -r1.3 -r1.3.8.1
--- noatun-plugins/tippercanoe/polygon.h	2001/04/16 22:04:03	1.3
+++ noatun-plugins/tippercanoe/polygon.h	2004/06/12 10:05:15	1.3.8.1
@@ -28,8 +28,8 @@ struct PolygonEngine : public Bitmap<Pix
 #define super (1<<superSampleShift)
   void apply(Pixel *dest) {
     Pixel sum=0;
-    int count = width*height;
-    Pixel *src = data;
+    int count = this->width*this->height;
+    Pixel *src = this->data;
     while(count--) {
       sum += *(src++);
       if (sum)
@@ -40,10 +40,10 @@ struct PolygonEngine : public Bitmap<Pix
 
   void add(Pixel color,int x,int y) {
     if (y < 0) return;
-    if (y >= height) return;
+    if (y >= this->height) return;
     if (x < 0) x = 0;
-    if (x > width) x = width;
-    data[x+y*width] += color;
+    if (x > this->width) x = this->width;
+    this->data[x+y*this->width] += color;
   }
 
   /* Color is char[layers] */
