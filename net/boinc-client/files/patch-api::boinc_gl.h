--- api/boinc_gl.h.orig	Wed Sep  1 19:15:30 2004
+++ api/boinc_gl.h	Fri Oct  1 12:06:47 2004
@@ -54,8 +54,6 @@
 #    include <OpenGL/glu.h>
 #  endif
 
-# include "GL/glut.h"
-/*
 #  if defined(HAVE_GLUT_H)
 #    include "glut.h"
 #  elif defined(HAVE_GL_GLUT_H)
@@ -65,7 +63,6 @@
 #  elif defined(HAVE_GLUT_GLUT_H)
 #    include <GLUT/glut.h>
 #  endif
-*/
 
 #endif // _WIN32
 
