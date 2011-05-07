--- src/display/canvas.h.orig	2010-06-26 14:05:07.000000000 +0200
+++ src/display/canvas.h	2011-04-09 11:21:30.000000000 +0200
@@ -48,7 +48,7 @@
 public:
   typedef std::vector<Attributes> attributes_list;
 
-  Canvas(int x = 0, int y = 0, int width = 0, int height = 0) :
+  Canvas(int x = 0, int y = 0, int width = 1, int height = 1) :
     m_window(newwin(height, width, y, x)) {}
   ~Canvas() { delwin(m_window); }
 
