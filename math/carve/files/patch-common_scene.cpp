--- common/scene.cpp.orig	2011-08-26 22:17:26.000000000 +0200
+++ common/scene.cpp	2014-02-13 15:16:11.000000000 +0100
@@ -31,7 +31,7 @@
 static int lastbutton = 0;
 
 static Scene *g_scene = NULL;
-static int g_mainWindow = NULL;
+static int g_mainWindow = 0;
 static GLUI *g_rightPanel = NULL;
 static double near_plane = 0.2;
 static double far_plane = 200;
@@ -412,7 +412,7 @@
     GLUI_Master.set_glutKeyboardFunc(s_key);
     GLUI_Master.set_glutSpecialFunc(NULL);
     GLUI_Master.set_glutMouseFunc(s_click);
-    GLUI_Master.set_glutMotionFunc(s_drag);
+    //GLUI_Master.set_glutMotionFunc(s_drag);
 
     g_rightPanel = GLUI_Master.create_glui_subwindow(g_mainWindow, GLUI_SUBWINDOW_RIGHT);
 
