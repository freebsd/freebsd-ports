--- cmake/FindGLX.cmake.orig	2017-04-06 09:27:56 UTC
+++ cmake/FindGLX.cmake
@@ -39,8 +39,8 @@ find_path(GLX_INCLUDE_DIRS
 	PATH_SUFFIXES include
 )
 if(GLX_INCLUDE_DIRS)
-	check_include_file(GL/gl.h HAVE_GL_GL_H)
-	check_include_file(GL/glx.h HAVE_GL_GLX_H)
+	check_include_file(GL/gl.h HAVE_GL_GL_H "-I${GLX_INCLUDE_DIRS}")
+	check_include_file(GL/glx.h HAVE_GL_GLX_H "-I${GLX_INCLUDE_DIRS}")
 endif()
 
 find_library(GL_LIBRARY
