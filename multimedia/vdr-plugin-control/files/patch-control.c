--- a/control.c
+++ b/control.c
@@ -69,6 +69,7 @@ cPluginControl::~cPluginControl()
   // Clean up after yourself!
   delete(_pReceivers);
   delete(_pTerminal);
+  delete(glCtrlState);
 }
 
 
