--- spunk/resed.h.orig	Fri Feb 21 12:05:28 1997
+++ spunk/resed.h	Mon Oct  9 12:07:54 2006
@@ -184,7 +184,7 @@
     void IDPrompt (i16& ID, int& Abort);
     void EditIDPrompt (i16& ID, int& Abort);
     void MinMaxPrompt (i32& Min, i32& Max, i32 MinVal, i32 MaxVal, int& Abort);
-    void ResEditApp::FMinMaxPrompt (double& Min, double& Max, double MinVal,
+    void FMinMaxPrompt (double& Min, double& Max, double MinVal,
                                 double MaxVal, int& Abort);
     void TextIDPrompt (String& Text, i16& ID, int& Abort);
     void DeleteRes ();
