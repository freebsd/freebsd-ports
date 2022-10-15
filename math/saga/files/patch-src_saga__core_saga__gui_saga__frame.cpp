--- src/saga_core/saga_gui/saga_frame.cpp.orig	2022-10-15 20:07:34 UTC
+++ src/saga_core/saga_gui/saga_frame.cpp
@@ -1290,9 +1290,9 @@ void CSAGA_Frame::TB_Add(wxToolBarBase *pToolBar, cons
 void CSAGA_Frame::TB_Add_Item(wxToolBarBase *pToolBar, bool bCheck, int Cmd_ID)
 {
 	if( bCheck )
-		((wxToolBar *)pToolBar)->AddTool(Cmd_ID, CMD_Get_Name(Cmd_ID), IMG_Get_Bitmap(CMD_Get_ImageID(Cmd_ID), pToolBar->GetToolBitmapSize()), CMD_Get_Help(Cmd_ID), wxITEM_CHECK);
+		((wxToolBar *)pToolBar)->AddTool(Cmd_ID, CMD_Get_Name(Cmd_ID), (wxBitmapBundle)IMG_Get_Bitmap(CMD_Get_ImageID(Cmd_ID), pToolBar->GetToolBitmapSize()), CMD_Get_Help(Cmd_ID), wxITEM_CHECK);
 	else
-		((wxToolBar *)pToolBar)->AddTool(Cmd_ID, CMD_Get_Name(Cmd_ID), IMG_Get_Bitmap(CMD_Get_ImageID(Cmd_ID), pToolBar->GetToolBitmapSize()), CMD_Get_Help(Cmd_ID));
+		((wxToolBar *)pToolBar)->AddTool(Cmd_ID, CMD_Get_Name(Cmd_ID), (wxBitmapBundle)IMG_Get_Bitmap(CMD_Get_ImageID(Cmd_ID), pToolBar->GetToolBitmapSize()), CMD_Get_Help(Cmd_ID));
 }
 
 //---------------------------------------------------------
