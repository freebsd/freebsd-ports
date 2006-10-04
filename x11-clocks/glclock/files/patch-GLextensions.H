--- GLextensions.H.orig	Thu Jun 22 16:36:07 2000
+++ GLextensions.H	Sun Oct  1 20:52:59 2006
@@ -12,6 +12,7 @@
 #pragma warning(disable : 4051)     // ALPHA
 #endif
 
+#define GL_GLEXT_PROTOTYPES
 
 #include <GL/gl.h>
 #include <GL/glut.h>
@@ -202,7 +203,7 @@
 
 
 // multitexture をサポートするバージョン（未定）
-#ifdef  GL_VERSION_1_
+#if 1
 #define GL_VERSION_multitexture
 #endif
 #define GL_VERSION_multitexture_F		9999.9f
@@ -232,13 +233,13 @@
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
@@ -592,6 +593,8 @@
 
 #endif	// #ifndef GL_ARB_texture_cube_map
 
+#define GL_EXT_texture_cube_map
+
 // EXT_texture_cube_map
 #ifndef GL_EXT_texture_cube_map
 #define GL_EXT_texture_cube_map
@@ -687,6 +690,8 @@
 #define GL_COMPRESSED_RGBA_S3TC_DXT3		((GLenum)0x83F2)
 #define GL_COMPRESSED_RGBA_S3TC_DXT5		((GLenum)0x83F3)
 #endif	// #ifndef GL_VERSION_texture_compression_s3tc
+
+#define GL_EXT_texture_compression_s3tc
 
 #ifndef GL_EXT_texture_compression_s3tc
 #define GL_EXT_texture_compression_s3tc
