--- src/RenderEPS.cc.orig	Tue Oct 15 02:11:32 2002
+++ src/RenderEPS.cc	Tue Oct 15 02:11:44 2002
@@ -48,7 +48,7 @@
 
 
 // constructor
-RenderEPS :: RenderEPS( char *fn, int sz=FB_BUFSIZE )
+RenderEPS :: RenderEPS( char *fn, int sz )
 {
 	bufsize = sz;
 	feedbackBuffer = (GLfloat *)malloc( bufsize*sizeof(GLfloat) );
