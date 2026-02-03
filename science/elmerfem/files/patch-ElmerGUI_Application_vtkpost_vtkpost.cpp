--- ElmerGUI/Application/vtkpost/vtkpost.cpp.orig	2026-01-22 12:37:18 UTC
+++ ElmerGUI/Application/vtkpost/vtkpost.cpp
@@ -137,6 +137,8 @@ using namespace std;
 
 using namespace std;
 
+#define GetRenderWindow renderWindow // renaming for VTK-9.2.2
+
 // Custom print for QtScript:
 //----------------------------
 #if QT_VERSION >= 0x040403
