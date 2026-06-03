--- core/vtk/ttkWRLExporter/ttkWRLExporter.cpp.orig	2024-09-20 10:44:28 UTC
+++ core/vtk/ttkWRLExporter/ttkWRLExporter.cpp
@@ -22,6 +22,7 @@
 #include <vtkTransform.h>
 #include <vtkUnsignedCharArray.h>
 #include <vtkVRMLExporter.h>
+#include <vtkVersionMacros.h>
 
 // base code includes
 #include <Debug.h>
@@ -145,7 +146,12 @@ TTKWRLEXPORTER_EXPORT void vtkVRMLExporter::WriteAnAct
     fprintf(fp, "            solid FALSE\n");
 
     if(!pointDataWritten) {
+
+#if VTK_VERSION_NUMBER >= VTK_VERSION_CHECK(9, 4, 20250513)
+      this->WritePointData(points, normals, tcoords, colors, false, fp);
+#else
       this->WritePointData(points, normals, tcoords, colors, fp);
+#endif
       pointDataWritten = 1;
     } else {
       fprintf(fp, "            coord  USE VTKcoordinates\n");
@@ -189,7 +195,11 @@ TTKWRLEXPORTER_EXPORT void vtkVRMLExporter::WriteAnAct
     fprintf(fp, "          geometry IndexedFaceSet {\n");
 
     if(!pointDataWritten) {
+#if VTK_VERSION_NUMBER >= VTK_VERSION_CHECK(9, 4, 20250513)
+      this->WritePointData(points, normals, tcoords, colors, false, fp);
+#else
       this->WritePointData(points, normals, tcoords, colors, fp);
+#endif
       pointDataWritten = 1;
     } else {
       fprintf(fp, "            coord  USE VTKcoordinates\n");
@@ -238,7 +248,11 @@ TTKWRLEXPORTER_EXPORT void vtkVRMLExporter::WriteAnAct
     fprintf(fp, "          geometry IndexedLineSet {\n");
 
     if(!pointDataWritten) {
+#if VTK_VERSION_NUMBER >= VTK_VERSION_CHECK(9, 4, 20250513)
+      this->WritePointData(points, nullptr, nullptr, colors, false, fp);
+#else
       this->WritePointData(points, nullptr, nullptr, colors, fp);
+#endif
     } else {
       fprintf(fp, "            coord  USE VTKcoordinates\n");
 
@@ -440,6 +454,9 @@ TTKWRLEXPORTER_EXPORT void
                                   vtkDataArray *normals,
                                   vtkDataArray *tcoords,
                                   vtkUnsignedCharArray *colors,
+#if VTK_VERSION_NUMBER >= VTK_VERSION_CHECK(9, 4, 20250513)
+                                  bool vtkNotUsed(cellData),
+#endif
                                   FILE *fp) {
 
   double *p;
