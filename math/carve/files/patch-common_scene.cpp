--- common/scene.cpp.orig	2011-12-01 12:05:53.000000000 +0100
+++ common/scene.cpp	2011-12-01 12:05:22.000000000 +0100
@@ -412,7 +412,7 @@
     GLUI_Master.set_glutKeyboardFunc(s_key);
     GLUI_Master.set_glutSpecialFunc(NULL);
     GLUI_Master.set_glutMouseFunc(s_click);
-    GLUI_Master.set_glutMotionFunc(s_drag);
+    //GLUI_Master.set_glutMotionFunc(s_drag);
 
     g_rightPanel = GLUI_Master.create_glui_subwindow(g_mainWindow, GLUI_SUBWINDOW_RIGHT);
 
