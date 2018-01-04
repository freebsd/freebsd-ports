--- VTK/ThirdParty/xdmf2/vtkxdmf2/libsrc/XdmfDsmComm.cxx.orig	2016-11-14 15:41:57 UTC
+++ VTK/ThirdParty/xdmf2/vtkxdmf2/libsrc/XdmfDsmComm.cxx
@@ -52,7 +52,7 @@ XdmfDsmComm::Receive(XdmfDsmMsg *Msg){
         XdmfErrorMessage("Cannot Receive Message of Length = " << Msg->Length);
         return(XDMF_FAIL);
     }
-    if(Msg->Data <= 0 ){
+    if(Msg->Data == 0 ){
         XdmfErrorMessage("Cannot Receive Message into Data Buffer = " << Msg->Length);
         return(XDMF_FAIL);
     }
@@ -66,7 +66,7 @@ XdmfDsmComm::Send(XdmfDsmMsg *Msg){
         XdmfErrorMessage("Cannot Send Message of Length = " << Msg->Length);
         return(XDMF_FAIL);
     }
-    if(Msg->Data <= 0 ){
+    if(Msg->Data == 0 ){
         XdmfErrorMessage("Cannot Send Message from Data Buffer = " << Msg->Length);
         return(XDMF_FAIL);
     }
