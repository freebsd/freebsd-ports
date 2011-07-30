--- src/gui/SceneViewFrame.cc.orig	2011-06-26 14:46:09.000000000 +0200
+++ src/gui/SceneViewFrame.cc	2011-06-26 14:46:56.000000000 +0200
@@ -50,10 +50,11 @@
       m_gui(layout.get_gui()),
       m_gl_area(m_gui.get_gl_config(), true),
       m_cameras_model(Gtk::ListStore::create(m_camera_cols)),
-      m_cameras(m_cameras_model),
       m_cam_id(0xFFFFFFFF),
       m_layer_table(2, 5, true)
 {
+    m_cameras.set_model(m_cameras_model);
+
     for( std::size_t i = 0; i < NUMBER_OF_LAYERS; ++i )
         m_layers[i] = (i == 0);
 
