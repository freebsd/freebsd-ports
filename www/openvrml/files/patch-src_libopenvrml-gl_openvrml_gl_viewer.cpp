--- ./src/libopenvrml-gl/openvrml/gl/viewer.cpp.orig	2007-11-11 09:51:10.000000000 +0100
+++ ./src/libopenvrml-gl/openvrml/gl/viewer.cpp	2007-11-19 22:12:07.000000000 +0100
@@ -1969,7 +1969,7 @@
 # ifdef HAVE_APPLE_OPENGL_FRAMEWORK
     typedef GLvoid (OPENVRML_GL_CALLBACK_* TessCB)(...);
 # else
-    typedef GLvoid (OPENVRML_GL_CALLBACK_* TessCB)(GLvoid);
+    typedef GLvoid (OPENVRML_GL_CALLBACK_* TessCB)();
 # endif
 
     /**
