--- src/RenderEPS.h.orig	Tue Oct 15 00:35:11 2002
+++ src/RenderEPS.h	Tue Oct 15 00:35:26 2002
@@ -23,6 +23,8 @@
 #include <GL/gl.h>
 #include <string>
 
+using namespace std;
+
 #define FB_BUFSIZE 1000000
 
 class RenderEPS {
