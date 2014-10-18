--- source/Irrlicht/COpenGLExtensionHandler.h.orig	2014-10-18 08:53:44 UTC
+++ source/Irrlicht/COpenGLExtensionHandler.h
@@ -59,6 +59,9 @@
 	#endif
 	#include <GL/gl.h>
 	#include <GL/glx.h>
+	#ifndef PFNGLBLENDEQUATIONPROC
+	typedef void (APIENTRYP PFNGLBLENDEQUATIONPROC) (GLenum mode);
+	#endif
 	#if defined(_IRR_OPENGL_USE_EXTPOINTER_)
 	#include "glext.h"
 	#undef GLX_ARB_get_proc_address // avoid problems with local glxext.h
