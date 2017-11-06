--- spunk/resed.h.orig	1997-02-21 11:05:28 UTC
+++ spunk/resed.h
@@ -184,7 +184,7 @@ protected:
     void IDPrompt (i16& ID, int& Abort);
     void EditIDPrompt (i16& ID, int& Abort);
     void MinMaxPrompt (i32& Min, i32& Max, i32 MinVal, i32 MaxVal, int& Abort);
-    void ResEditApp::FMinMaxPrompt (double& Min, double& Max, double MinVal,
+    void FMinMaxPrompt (double& Min, double& Max, double MinVal,
                                 double MaxVal, int& Abort);
     void TextIDPrompt (String& Text, i16& ID, int& Abort);
     void DeleteRes ();
