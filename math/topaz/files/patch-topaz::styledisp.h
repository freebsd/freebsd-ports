--- topaz/styledisp.h.orig	Wed Dec  4 23:02:28 2002
+++ topaz/styledisp.h	Fri Dec 27 04:44:03 2002
@@ -26,6 +26,8 @@
 
 #include <string>
 
+using namespace std;
+
 extern bool getlinestylename(int id, string *out);
 bool getcolorname(unsigned int r, unsigned int g,unsigned int b, string *out);
 bool getmarkerstylename(int id, string *out);
