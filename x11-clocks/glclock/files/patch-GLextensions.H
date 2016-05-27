--- GLextensions.H.orig	2000-06-22 14:36:07 UTC
+++ GLextensions.H
@@ -12,6 +12,7 @@
 #pragma warning(disable : 4051)     // ALPHA
 #endif
 
+#define GL_GLEXT_PROTOTYPES
 
 #include <GL/gl.h>
 #include <GL/glut.h>
@@ -202,7 +203,7 @@ float GetOpenGLVersion() ;
 
 
 // multitexture をサポートするバージョン（未定）
-#ifdef  GL_VERSION_1_
+#if 1
 #define GL_VERSION_multitexture
 #endif
 #define GL_VERSION_multitexture_F		9999.9f
@@ -232,13 +233,13 @@ float GetOpenGLVersion() ;
 #define GL_VERSION_polygon_offset_F		1.1f
 
 // texture_cube_map をサポートするバージョン（未定）
-#ifdef  GL_VERSION_1_
+#if 1
 #define GL_VERSION_texture_cube_map
 #endif
 #define GL_VERSION_texture_cube_map_F	9999.9f
 
 // texture_compression をサポートするバージョン（未定）
-#ifdef  GL_VERSION_1_
+#if 1
 #define GL_VERSION_texture_compression
 #endif
 #define GL_VERSION_texture_compression_F	9999.9f
@@ -592,6 +593,8 @@ char *IsSupported_multitexture(int flag_
 
 #endif	// #ifndef GL_ARB_texture_cube_map
 
+#define GL_EXT_texture_cube_map
+
 // EXT_texture_cube_map
 #ifndef GL_EXT_texture_cube_map
 #define GL_EXT_texture_cube_map
@@ -688,6 +691,8 @@ char *IsSupported_texture_compression_En
 #define GL_COMPRESSED_RGBA_S3TC_DXT5		((GLenum)0x83F3)
 #endif	// #ifndef GL_VERSION_texture_compression_s3tc
 
+#define GL_EXT_texture_compression_s3tc
+
 #ifndef GL_EXT_texture_compression_s3tc
 #define GL_EXT_texture_compression_s3tc
 
