--- src/core/ozone/gl_surface_glx_qt.cpp.orig	2019-01-16 22:42:58 UTC
+++ src/core/ozone/gl_surface_glx_qt.cpp
@@ -173,7 +173,7 @@ bool GLSurfaceGLXQt::Initialize(GLSurfaceFormat format
         GLX_PBUFFER_HEIGHT, m_size.height(),
         GLX_LARGEST_PBUFFER, x11::False,
         GLX_PRESERVED_CONTENTS, x11::False,
-        NULL
+	GLX_NONE
     };
 
     m_surfaceBuffer = glXCreatePbuffer(display, static_cast<GLXFBConfig>(g_config), pbuffer_attributes);
