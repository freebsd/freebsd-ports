
$FreeBSD$

--- agent.h.orig
+++ agent.h
@@ -70,7 +70,7 @@
   inline double width()  {return width_;}
   inline double height() {return height_;}
   virtual void findClosestCornertoPoint(double x, double y, 
-               double &corner_x, double &corner_y) const = NULL; 
+               double &corner_x, double &corner_y) const = 0; 
   virtual void place(double x, double y);
   void label(const char* name, int anchor);
   void color(const char* name);
