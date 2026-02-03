--- ElmerGUI/Application/vtkpost/vtkpost.cpp.orig	2020-11-10 19:52:44 UTC
+++ ElmerGUI/Application/vtkpost/vtkpost.cpp
@@ -124,6 +124,8 @@
 
 using namespace std;
 
+#define GetRenderWindow renderWindow // renaming for VTK-9.2.2
+
 // Custom print for QtScript:
 //----------------------------
 #if QT_VERSION >= 0x040403
@@ -171,7 +173,7 @@ static void pEventHandler(vtkObject* caller, unsigned 
   QVTKWidget* qvtkWidget = vtkPost->GetQVTKWidget();
 #endif
 
-  vtkAbstractPicker* picker = qvtkWidget->GetInteractor()->GetPicker();
+  vtkAbstractPicker* picker = qvtkWidget->interactor()->GetPicker();
   vtkPropPicker* propPicker = vtkPropPicker::SafeDownCast(picker);
 
   vtkActor* actor = propPicker->GetActor();
@@ -382,14 +384,14 @@ VtkPost::VtkPost(QWidget *parent)
   // Create a cell picker and set the callback & observer:
   //------------------------------------------------------
   vtkPropPicker* propPicker = vtkPropPicker::New();
-  qvtkWidget->GetInteractor()->SetPicker(propPicker);
+  qvtkWidget->interactor()->SetPicker(propPicker);
   propPicker->Delete();
 
   vtkCallbackCommand* cbcPick = vtkCallbackCommand::New();
   cbcPick->SetClientData(this);
   cbcPick->SetCallback(pEventHandler);
 
-  vtkAbstractPicker* picker = qvtkWidget->GetInteractor()->GetPicker();
+  vtkAbstractPicker* picker = qvtkWidget->interactor()->GetPicker();
   picker->AddObserver(vtkCommand::EndPickEvent, cbcPick);
   cbcPick->Delete();
 
@@ -402,7 +404,7 @@ VtkPost::VtkPost(QWidget *parent)
   cbcPlane->SetCallback(iEventHandler);
 
   planeWidget = vtkImplicitPlaneWidget::New();
-  planeWidget->SetInteractor(qvtkWidget->GetInteractor());
+  planeWidget->SetInteractor(qvtkWidget->interactor());
   planeWidget->AddObserver(vtkCommand::InteractionEvent, cbcPlane);
   cbcPlane->Delete();
 
@@ -3519,4 +3521,4 @@ void VtkPost::viewZXmPlaneSlot(){
   renderer->GetActiveCamera()->SetViewUp(1,0,0);
   renderer->ResetCamera();
   redrawSlot();
-}
\ No newline at end of file
+}
