--- src/MathCtrl.h.orig	2015-02-05 22:22:16 UTC
+++ src/MathCtrl.h
@@ -211,7 +211,7 @@ protected:
   void OnCharNoActive(wxKeyEvent& event);
   void OnChar(wxKeyEvent& event);
   void SelectEditable(EditorCell *editor, bool up);
-  void SelectWithChar(wxChar ccode);
+  void SelectWithChar(int ccode);
   void ClickNDrag(wxPoint down, wxPoint up);
   void AdjustSize();
   void OnEraseBackground(wxEraseEvent& event) { }
