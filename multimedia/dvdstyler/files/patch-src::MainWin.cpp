--- src/MainWin.cpp.orig	Tue Aug  3 16:02:33 2004
+++ src/MainWin.cpp	Fri Aug  6 19:43:32 2004
@@ -403,7 +403,7 @@
   else
 	d = m_menuBox->GetScaleValue()*100;
   //st = wxString::Format(_T("%0.2f"), d); if (d == (int) d)
-  st = wxString::Format(_T("%d"), (int)round(d));
+  st = wxString::Format(_T("%d"), rint(d));
   m_scaleCB->SetValue(st + _T("%"));
 }
 
