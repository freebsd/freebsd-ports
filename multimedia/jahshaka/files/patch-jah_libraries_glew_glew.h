--- jah/libraries/glew/glew.h.orig
+++ jah/libraries/glew/glew.h
@@ -8945,11 +8945,15 @@
 }
 #endif
 
+/* Do not undef GLAPIENTRY here. This is a quick hack to avoid
+   undefined symbols when including glut.h just after glew.h */
+/*
 #ifdef GLEW_APIENTRY_DEFINED
 #undef GLEW_APIENTRY_DEFINED
 #undef APIENTRY
 #undef GLAPIENTRY
 #endif
+*/
 
 #ifdef GLEW_CALLBACK_DEFINED
 #undef GLEW_CALLBACK_DEFINED
