===================================================================
RCS file: /usr/repos/kde/kdeaddons/noatun-plugins/synaescope/polygon.h,v
retrieving revision 1.4
retrieving revision 1.4.8.1
diff -u -p -r1.4 -r1.4.8.1
--- noatun-plugins/synaescope/polygon.h	2001/04/16 23:20:34	1.4
+++ noatun-plugins/synaescope/polygon.h	2004/06/12 09:54:09	1.4.8.1
@@ -31,8 +31,8 @@ struct PolygonEngine : public Bitmap<Pix
 	void apply(Pixel *dest)
 	{
 		Pixel sum=0;
-		int count = width*height;
-		Pixel *src = data;
+		int count = this->width*this->height;
+		Pixel *src = this->data;
 		while(count--) {
 			sum += *(src++);
 			if (sum)
@@ -44,10 +44,10 @@ struct PolygonEngine : public Bitmap<Pix
 	void add(Pixel color,int x,int y)
 	{
 		if (y < 0) return;
-		if (y >= height) return;
+		if (y >= this->height) return;
 		if (x < 0) x = 0;
-		if (x > width) x = width;
-		data[x+y*width] += color;
+		if (x > this->width) x = this->width;
+		this->data[x+y*this->width] += color;
 	}
 
 	/* Color is char[layers] */
