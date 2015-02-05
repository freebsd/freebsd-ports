--- src/MathCtrl.cpp.orig	2015-02-05 22:22:12 UTC
+++ src/MathCtrl.cpp
@@ -1563,7 +1563,7 @@ void MathCtrl::OnCharInActive(wxKeyEvent
  * We have a wxKeyEvent with no active editor, shift is down and
  * keycode (ccode) is WXK_UP/WXK_DOWN
  */
-void MathCtrl::SelectWithChar(wxChar ccode) {
+void MathCtrl::SelectWithChar(int ccode) {
   // start making a selection
   // m_hCaretPositionStart is the first group selected
   // m_hCaretPositionEnd is tle last group selected
@@ -1646,7 +1646,7 @@ void MathCtrl::SelectEditable(EditorCell
 }
 
 void MathCtrl::OnCharNoActive(wxKeyEvent& event) {
-  wxChar ccode = event.GetKeyCode();
+  int ccode = event.GetKeyCode();
   wxString txt; // Usually we open an Editor Cell with initial content txt
 
   // If Shift is down we are selecting with WXK_UP and WXK_DOWN
