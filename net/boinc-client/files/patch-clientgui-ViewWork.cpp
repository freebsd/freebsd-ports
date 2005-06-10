--- clientgui/ViewWork.cpp.orig	Sun May 29 03:12:00 2005
+++ clientgui/ViewWork.cpp	Wed Jun  8 15:30:28 2005
@@ -569,7 +569,7 @@
     strBuffer.Clear();
 
     RESULT* rp = pDoc->result(item);
-    if (rp->active_task) {
+    if (! rp->active_task) {
         if(rp->state < RESULT_COMPUTE_ERROR)
             strBuffer.Printf(wxT("%.2f%%"), 0.0);
         else 
