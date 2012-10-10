--- Rendering/vtkTkRenderWidget.cxx.orig
+++ Rendering/vtkTkRenderWidget.cxx
@@ -941,8 +941,9 @@ static int vtkTkRenderWidget_MakeRenderWindow(struct vtkTkRenderWidget *self)
     vtkTclGetObjectFromPointer(self->Interp, self->RenderWindow,
                                "vtkRenderWindow");
 #endif
-    self->RW = ckalloc(
-      static_cast<unsigned int>(strlen(Tcl_GetStringResult(self->Interp)) + 1));
+    // in Tcl 8.6.x, ckalloc was changed to return "void *".
+    self->RW = static_cast<char *>(ckalloc(
+      static_cast<unsigned int>(strlen(Tcl_GetStringResult(self->Interp)) + 1)));
     strcpy(self->RW, Tcl_GetStringResult(self->Interp));
     Tcl_ResetResult(self->Interp);
     }
@@ -1113,8 +1114,9 @@ vtkTkRenderWidget_MakeRenderWindow(struct vtkTkRenderWidget *self)
     vtkTclGetObjectFromPointer(self->Interp, self->RenderWindow,
           "vtkRenderWindow");
 #endif
-    self->RW = ckalloc(
-      static_cast<unsigned int>(strlen(Tcl_GetStringResult(self->Interp)) + 1));
+    // in Tcl 8.6.x, ckalloc was changed to return "void *".
+    self->RW = static_cast<char *>(ckalloc(
+      static_cast<unsigned int>(strlen(Tcl_GetStringResult(self->Interp)) + 1)));
     strcpy(self->RW, Tcl_GetStringResult(self->Interp));
     Tcl_ResetResult(self->Interp);
     }
@@ -1306,8 +1308,9 @@ vtkTkRenderWidget_MakeRenderWindow(struct vtkTkRenderWidget *self)
     vtkTclGetObjectFromPointer(self->Interp, self->RenderWindow,
           "vtkRenderWindow");
 #endif
-    self->RW = ckalloc(
-      static_cast<unsigned int>(strlen(Tcl_GetStringResult(self->Interp)) + 1));
+    // in Tcl 8.6.x, ckalloc was changed to return "void *".
+    self->RW = static_cast<char *>(ckalloc(
+      static_cast<unsigned int>(strlen(Tcl_GetStringResult(self->Interp)) + 1)));
     strcpy(self->RW, Tcl_GetStringResult(self->Interp));
     Tcl_ResetResult(self->Interp);
     }
