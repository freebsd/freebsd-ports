GLObject.cpp:843:22: error: non-constant-expression cannot be narrowed from type 'double' to 'GLfloat' (aka 'float') in initializer list [-Wc++11-narrowing]
        GLfloat lamb[4] = { color[0] * 0.1, color[1] * 0.1, color[2] * 0.1, 1.0f } ;
                                    ^~~~~~~~~~~~~~

--- GLObject.cpp.orig	2018-07-09 11:47:42 UTC
+++ GLObject.cpp
@@ -840,7 +840,7 @@ void SetDirectionalLight(GLenum light, GLfloat pos[4],
 						 GLfloat amb, GLfloat specularFlag, GLfloat bright, GLfloat *modulate)
 {
 	GLfloat color[4] = { colorRGBA[0], colorRGBA[1], colorRGBA[2], 1.0f } ;	// colorRGBA[3] } ;
-	GLfloat	lamb[4] = { color[0] * 0.1, color[1] * 0.1, color[2] * 0.1, 1.0f } ;
+	GLfloat	lamb[4] = { color[0] * 0.1f, color[1] * 0.1f, color[2] * 0.1f, 1.0f } ;
 	static GLfloat	u_pos[4] ;
 	static GLfloat	spec[4] = { 0.0f, 0.0f, 0.0f, 1.0f } ;
 
