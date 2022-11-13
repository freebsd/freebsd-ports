- workaround for https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=267115 to allow to build with mpv-0.35

diff -Nur lib/media/src/mpv/mpvwidget.cpp.orig lib/media/src/mpv/mpvwidget.cpp
--- lib/media/src/mpv/mpvwidget.cpp.orig
+++ lib/media/src/mpv/mpvwidget.cpp
@@ -30,7 +30,11 @@
     qDebug() << "initializeGL" << nativeParent;
     if (nativeParent == nullptr) qFatal("No native parent");
 
-    mpv_opengl_init_params gl_init_params{get_proc_address, this, nullptr};
+    #if MPV_CLIENT_API_VERSION < MPV_MAKE_VERSION(2,0)
+	mpv_opengl_init_params gl_init_params{get_proc_address, this, nullptr};
+    #else
+	mpv_opengl_init_params gl_init_params{get_proc_address, this};
+    #endif
     mpv_render_param params[]{{MPV_RENDER_PARAM_API_TYPE, (void *)MPV_RENDER_API_TYPE_OPENGL},
                               {MPV_RENDER_PARAM_OPENGL_INIT_PARAMS, &gl_init_params},
                               {MPV_RENDER_PARAM_INVALID, nullptr},
